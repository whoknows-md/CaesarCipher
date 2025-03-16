// Caesar Cipher Encryption and Decryption Algorithm using C++

#include <iostream>
#include <string>
using namespace std;

string encryption(string text, int shift)
{
    string cipher = "";
    shift %= 26;
    for (char i : text)
    {
        if (isalpha(i))
        {
            char base = islower(i) ? 'a' : 'A';
            char c = (i - base + shift) % 26 + base;
            cipher += c;
        }
        else
        {
            cipher += i;
        }
    }
    return cipher;
}

string decryption(string text, int shift)
{
    shift %= 26;
    return encryption(text, 26 - shift);
}

int main()
{
    while (true)
    {
        string text;
        cout << "Enter the text: ";
        getline(cin, text);

        int shift;
        cout << "Enter the shift: ";
        cin >> shift;

        string statement = "Type ('Encrypt' or 'encrypt' for encryption) and ('Decrypt' or 'decrypt' for decryption)...";
        cout << statement << endl;

        string input_statement;
        cin >> input_statement;

        if (input_statement == "Encrypt" || input_statement == "encrypt")
        {
            cout << "The Encrypted text is: " << encryption(text, shift) << endl;
        }
        else if (input_statement == "Decrypt" || input_statement == "decrypt")
        {
            cout << "The Decrypted text is: " << decryption(text, shift) << endl;
        }
        else
        {
            cout << "Enter a valid statement..." << endl;
        }

        char repeat;
        cout << "Do you want to repeat... Enter 'n' or 'N' for No, any other key for Yes..." << endl;
        cin >> repeat;
        cin.ignore();

        if (repeat == 'n' || repeat == 'N')
        {
            break;
        }
    }
    return 0;
}