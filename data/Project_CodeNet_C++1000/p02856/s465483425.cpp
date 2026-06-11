#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll M;
    cin >> M;
    vector<ll> d(M), c(M);
    rep(i, M) cin >> d[i] >> c[i];
    ll num = 0;
    ll ans = 0;
    rep(i, M) {
        ans += c[i];
        num += c[i] * d[i];
    }
    --ans;

    ll tmp = num;
    while (tmp > 9) {
        ans += max(0LL, tmp / 10 - 1);
        tmp /= 10;
    }

    while (num > 9) {
        ll tmp = num;

        num = 0;
        while (tmp > 0) {
            num += tmp % 10;
            tmp /= 10;
            ++ans;
        }
        --ans;

        tmp = num;
        while (tmp > 9) {
            ans += max(0LL, tmp / 10 - 1);
            tmp /= 10;
        }
    }
    cout << ans << endl;
}
