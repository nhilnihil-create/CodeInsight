#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int MAX = 1e9;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, k, s;
    cin >> n >> k >> s;
    vector<int> ans;

    if (k == 0) {
        if (s != MAX) REP(i, n) ans.push_back(MAX);
        else REP(i, n) ans.push_back(MAX - 1);
    } else if (n == k) {
        REP(i, n) ans.push_back(s);
    } else {
        if (s != MAX) {
            REP(i, k) ans.push_back(s);
            REP(i, n - k) ans.push_back(MAX);
        } else {
            REP(i, k) ans.push_back(MAX);
            REP(i, n - k) ans.push_back(MAX - 1);
        }
    }

    REP(i, n) {
        cout << ans[i];
        if (i != n - 1) cout << ' ';
    }
    cout << '\n';
    return 0;
}