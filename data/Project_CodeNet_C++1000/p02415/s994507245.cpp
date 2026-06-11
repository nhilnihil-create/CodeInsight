#include <iostream>
#include <string>
using namespace std;

int main()
{
    string line;
    getline(cin, line);
    for (auto &c: line){
        if (islower(c)){
            putchar(toupper(c));
        }else{
            putchar(tolower(c));
        }
    }
    cout << endl;
}