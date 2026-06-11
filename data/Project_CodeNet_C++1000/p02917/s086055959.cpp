#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647 -> 10桁
// MAX ll 9,223,372,036,854,775,807 -> 19桁
// MAX O(n) 10^8 -> 8回
// double pi = M_PI or acos(-1)
// printf("%.10f\n", ans);

int main() {
    int n;
    cin >> n;
    vector<int> b(n - 1);
    rep(i, n - 1) cin >> b.at(i);
    vector<int> a(n);
    a.at(0) = b.at(0);

    rep(i, n - 1) {
        if (a.at(i) > b.at(i)) a.at(i) = b.at(i);
        for (int j = a.at(i); j <= b.at(i); j++) {
            a.at(i + 1) = j;
        }
    }

    ll ans = 0;
    rep(i, n) {
        ans += a.at(i);
    }

    cout << ans << endl;

    return 0;
}
