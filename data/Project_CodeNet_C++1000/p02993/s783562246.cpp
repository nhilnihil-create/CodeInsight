/**
*    created: 12.05.2020 00:57:08
**/
#include <bits/stdc++.h>
#define int long long
const int INF = 1e18L + 5;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    string s; cin >> s;
    if (s[0] == s[1] || s[1] == s[2] || s[2] == s[3]) cout << "Bad" << endl;
    else cout << "Good" << endl;
    return 0;
}