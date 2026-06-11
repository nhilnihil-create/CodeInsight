#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 77;

int main(){
    string s;
    cin >> s;
    int n = 0;
    for(char i : s) n += i-'0';
    if(n%9==0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}