#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int main(){
    string name;

    // cout << "Please input your name.\n>>";
    cin >> name;

    if(3 <= name.length() && name.length() <= 20){
        // cout << "Your name is [" << name << "].\n";
        string nickname;
        nickname = name.substr(0,3);
        cout << nickname << "\n";
    } else {
        cout << "Your name is invalid data...\n";
        return 0;
    }    
}