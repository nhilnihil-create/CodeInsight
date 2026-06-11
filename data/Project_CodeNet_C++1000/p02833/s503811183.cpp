#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll N;
    cin >> N;

    if (N % 2 == 1)
        cout << 0 << endl;
    else {
        ll ans = 0;
        for (ll i = 5; i <= N; i *= 5) {
            ans += N / 2 / i;
        }
        cout << ans << endl;
    }
}