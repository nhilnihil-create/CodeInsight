#include<iostream>
using namespace std;
int main(){
    string s;
    cin >> s;
    bool A = s[0] == 'R';
    bool B = s[1] == 'R';
    bool C = s[2] == 'R';
    if(A && B && C)        cout << 3 << endl;
    else if( (A && B) || (B && C))  cout << 2 << endl;
    else if(A || B || C) cout << 1 << endl;
    else cout << 0;
}