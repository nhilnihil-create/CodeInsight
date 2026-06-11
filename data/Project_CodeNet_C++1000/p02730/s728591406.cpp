#include <bits/stdc++.h>
using namespace std;

bool palindrome(string s){
    int n = s.length();
    string former = s.substr(0,n/2);
    reverse(s.begin(), s.end());
    string latter = s.substr(0,n/2);

    //cout << former << " " << latter << endl;

    if(former == latter) return true;
    else return false;
}

int main(){
    string s;
    cin >> s;

    int n = s.length();
    string s2 = s.substr(0,(n-1)/2);
    string s3 = s.substr((n+3)/2-1);

    //cout << s2 << " " << s3 << endl;

    if(palindrome(s) == true
    && palindrome(s2) == true
    && palindrome(s3) == true) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}