#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
const int INF = 1001001001;
// MAX int 2,147,483,647 -> 10桁
// MAX ll 9,223,372,036,854,775,807 -> 19桁
// MAX O(n) 10^8 -> 8回
// double pi = M_PI or acos(-1)
// printf("%.10f\n", ans);

int main() {
    int n;
    cin >> n;
    vector<ll> a(n + 1), b(n);
    rep(i, n + 1) cin >> a.at(i);
    rep(i, n) cin >> b.at(i);

    ll preSum = 0;
    rep(i, n + 1) {
        preSum += a.at(i);
    }

    rep(i, n) {
        if (a.at(i) >= b.at(i)) {
            a.at(i) -= b.at(i);
        } else {
            b.at(i) -= a.at(i);
            a.at(i) = 0;
            if (a.at(i + 1) >= b.at(i)) {
                a.at(i + 1) -= b.at(i);
            } else {
                a.at(i + 1) = 0;
            }
        }
    }

    ll afterSum = 0;
    rep(i, n + 1) {
        afterSum += a.at(i);
    }

    ll ans = preSum - afterSum;

    cout << ans << endl;

    return 0;
}
