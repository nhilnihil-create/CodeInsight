#include "bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

#define int long long

#ifndef bhupixb
    #define var(...)
    #define stl(...)
#endif

#define single_test

void solve() {
    string s;
    cin >> s;
    if (s.back() == 's') {
        s += "es";
    }
    else {
        s += 's';
    }
    cout << s << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    #ifndef single_test
        cin >> t;
    #endif
    for (int i = 1; i <= t; ++i) {
        // cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}