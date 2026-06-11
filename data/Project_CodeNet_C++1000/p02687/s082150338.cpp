#define _GLIBCXX_DEBUG
#include <iostream>
#include <string>
using namespace std;

int main(void){
    string s;
    cin >> s;
    if(s=="ABC") cout << "ARC\n";
    if(s=="ARC") cout << "ABC\n";
    return 0;
}