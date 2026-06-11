#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define len(a) (int)a.size()
using namespace std;
const int INF = 1e9;

int main() {
    string s, t; cin >> s >> t;
    int n = len(s)-len(t)+1;
    int ans = INF;
    rep(i, n) {
        int cost = 0;
        rep(j, len(t)) {
            if (t[j] != s[i+j]) cost++;
        }
        ans = min(cost, ans);
    }
    cout << ans << endl;
}
