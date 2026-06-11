#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647 -> 10桁
// MAX ll 9,223,372,036,854,775,807 -> 19桁
// MAX O(n) 10^18 -> 18回
// double pi = M_PI or acos(-1)

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> h(n);
    rep(i, n) cin >> h.at(i);
    vector<bool> ok(n, true);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (h[a] <= h[b]) ok.at(a) = false;
        if (h[b] <= h[a]) ok.at(b) = false;
    }
    int ans = 0;
    rep(i, n) {
        if (ok.at(i)) ans++;
    }

    cout << ans << endl;

    return 0;
}
