#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int mod = 1000000007;

int main() {
    ll N, K;
    cin >> N >> K;

    ll ans = 0;
    for (ll i = K; i <= N + 1; ++i) {
        ans = (ans + (i * ((N + 1 - i + 1) + N + 1) / 2 - i * (i + 1) / 2 + 1) %
                         mod) %
              mod;
    }

    cout << ans << endl;
}