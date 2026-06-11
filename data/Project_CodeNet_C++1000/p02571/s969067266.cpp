#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using pii = pair<int, int>;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    //
    string s, t; cin >> s >> t;

    int min_cnt = 1000;
    rep(i, s.length() - t.length() + 1) {
        int cnt = 0;
        rep(j, t.length()) {
            if (s[i+j] != t[j]) cnt++;
        }
        if (min_cnt > cnt) min_cnt = cnt;
    }

    cout << min_cnt << endl;
    //

    return 0;
}
