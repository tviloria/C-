/*
 *  Caesar Cipher (Shift Cipher, Caesar's code, or Caesar Shift).
 *  Description: Has the option to Encrypt and Decrypt. Special characters are also shifted.
 *
 *  Took inspiration from others on Stack Overflow to do this.
 *
 *
 */
#include <iostream>
#include <stdlib.h>
#include <string>


std::string encrypt(std::string text, int key);
std::string decrypt(std::string text, int key);

int main() {
    int key;
    char option;
    std::string caesar;
    printf("_________________Welcome to the Caesar Cipher Program_________________\n"
           "| Choose one of the following options.                                |\n"
           "| (1) Encrypt your Text                                               |\n"
           "| (2) Decrypt your Text                                               |\n"
           "| (E or e) Exit                                                       |\n"
           "|_____________________________________________________________________|\n");

    std::cin >> option;

    // Encrypt option

    switch(option) {
        case '1': {

            // Encryption key
            std::cout << "Enter shift key \n";
            std::cin >> key;

            std::cin.ignore();

            std::cout << "Enter Text to encrypt: \n";
            std::getline(std::cin, caesar);
            std::cout << "Encrypted Text: \n" << encrypt(caesar, key);

        }break;

        // Decrypt option
        case '2':{
            std::cout << "Enter shift key \n";
            std::cin >> key;

            std::cin.ignore();

            std::cout << "Enter Text to decrypt: \n";
            std::getline(std::cin, caesar);

            std::cout << "Decrypted text: \n" << decrypt(caesar, key);
        }break;

        case 'E':
        case 'e':{
            std::cout << "Exiting";
            return 0;
        }
        default: {
            std::cout << "Invalid Input";
        }break;
    }
    return 0;
}

// Encrypt function
std::string encrypt(std::string text, int key){
    std::string encryptIt = text;
    int move;
    // Loop through the text phrase
    for(int i = 0; i < (int)text.length() && text[i] != '\0'; i++){
        // Ascii Space character
        if(text[i] == 32){
            continue;
        }
        else{
            // move back Lowercase z to a
            if((text[i] + key) > 122) {
                move = (text[i] + key) - 122;
                encryptIt[i] = 96 + move;
            }
            // move back Uppercase Z to A
            else if((text[i] + key) > 90 && (text[i] + key) <= 96){
                move = (text[i] + key) - 90;
                encryptIt[i] = 64 + move;

            }
            // Any characters in between the Upper and Lower Alphabet ignore.
            else{
                encryptIt[i] += key;
            }
        }
    }
    return encryptIt;
}

// Decrypt function
std::string decrypt(std::string text, int key){
    std::string decryptIt = text;
    int move;

    for(int x = 0; x < (int)text.length(); x++){

        if(text[x] == 32){
            continue;
        }
        else{
            if((text[x] - key) > 90 && (text[x] - key) <= 96){
                move = (text[x] - key) + 26;
                decryptIt[x] = move;
            }
            else if((text[x] - key) < 65){
                move = (text[x] - key) + 26;
                decryptIt[x] = move;
            }
            else{
                decryptIt[x]  = text[x] - key;
            }
        }
    }

    return decryptIt;
}
