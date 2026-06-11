#include <bits/stdc++.h>
using namespace std;
 
int main(){
    string s;
    cin >> s;
    if(s[0] == s[1]){
        if(s[2] == s[3] && s[2] != s[1]){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }else{
        vector<char> a(2);
        vector<char> b(2);
        a[0] = s[0];
        a[1] = s[1];
        b[0] = s[2];
        b[1] = s[3];
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        if(a == b){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}