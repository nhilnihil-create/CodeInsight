#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    string s; cin >> s; int ok = 0;
    sort(s.begin(), s.end());
    if(s[0] == s[1] && s[2] != s[0] && s[2] == s[3]) ok = 1;    
    cout << (ok ? "Yes" : "No");
}