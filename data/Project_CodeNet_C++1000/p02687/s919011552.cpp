#include <iostream>
using namespace std;

#include <string>
#include <vector>
int main(){
    string str; cin >> str;
    if(str[1]=='B') str[1]='R';
    else str[1]='B';
    cout << str << endl;
}