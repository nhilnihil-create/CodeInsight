#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep2(i,x,n) for (int i = x; i < n; i++)
using ll = long long int;
int main() {
    string s,t; cin >> s >> t;
    bool ans = true;
    rep(i,s.size()) {
        if(s[i] != t[i]) ans = false;
    }
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}