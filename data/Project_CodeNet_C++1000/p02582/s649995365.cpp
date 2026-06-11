#define _GLIBCXX_DEBUG
#include <iostream>
#include <string>
using namespace std;

int main(void){
    string s;
    cin >> s;
    int a = 0, t = 0;
    for(char &c : s){
        if(c == 'R') t++;
        else t = 0;
        if(t > a) a = t;
    }
    cout << a << '\n';
    return 0;
}