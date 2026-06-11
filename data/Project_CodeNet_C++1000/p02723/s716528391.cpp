#include <bits/stdc++.h>
#define int long long
#pragma GCC optimize("O3,Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("avx,avx2,sse")
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    if (s[2] == s[3] && s[4] == s[5]) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }

    fflush(stdout);
    return 0;
}
