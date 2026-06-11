#define _GLIBCXX_DEBUG
#include <iostream>
#include <string>
using namespace std;

int main(void){
    string s, t;
    cin >> s >> t;
    int i=0;
    for(char &c : s){
        if(c == t[i]) i++;
        else{
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}