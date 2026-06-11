#include <bits/stdc++.h>

using namespace std;

int main() {
    int n , k , r , s , p;
    string t;
    cin >> n >> k >> r >> s >> p >> t;

    string played(n , 'n');

    auto opp = [](char c) {
        if (c == 'r') return 'p';
        if (c == 's') return 'r';
        return 's';
    };

    auto score = [&](char c) {
        if (c == 'r') return r;
        if (c == 's') return s;
        return p;
    };

    int ans = 0;
    for (int i = 0 ;i < n ;i++) {
        char want = opp(t[i]);
        if (i < k || played[i - k] != want) {
            ans += score(want);
            played[i] = want;
        }
    }

    cout << ans;
}
