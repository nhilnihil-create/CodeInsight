#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    int n;
    cin >> n;
    vi a(n+1);
    rep(i, n) cin >> a.at(i+1);
    vector<ll> dp(n+1);
    dp.at(0) = 1000;
    for (int k = 1; k <= n; k++) {
        dp.at(k) = 0;
        for (int i = 0; i < k-1; i++) {
            int m = 99999;
            for (int j = i+1; j < k; j++){
                m = min(m, a.at(j));
            }
            dp.at(k) = max(dp.at(k), dp.at(i)/m*a.at(k)+dp.at(i)%m);
        }
    }
    ll x = 0;
    rep(i, n+1) x = max(x, dp.at(i));
    cout << x << endl;
    return 0;
}