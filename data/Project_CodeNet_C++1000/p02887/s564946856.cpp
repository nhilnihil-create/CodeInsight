/**
 *    author:  FromDihPout
 *    created: 2020-08-09
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    string s;
    cin >> n >> s;
    char prev = '*';
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != prev) {
            prev = s[i];
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}