#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string s, sr;
    cin >> s;
    int n = s.length();
    sr = s;
    reverse(sr.begin(), sr.end());
    bool ok = true;
    if(s != sr)ok = false;
    if(s.substr(0, (n-1)/2) != sr.substr((n+1)/2))ok = false;
     if(sr.substr(0, (n-1)/2) != s.substr((n+1)/2))ok = false;
 
    if(ok)cout << "Yes" << endl;
    else cout << "No" << endl;
   
 
    return 0;
}