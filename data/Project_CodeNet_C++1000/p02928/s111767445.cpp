#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int mod = 1000000007;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    ll S = K * (K - 1) / 2 % mod;
    ll ans = 0;
    rep(i, N) {
        ll x = 0;
        ll y = 0;
        rep(j, N) {
            if (A[i] > A[j]) {
                ++x;
                if (i < j) ++y;
            }
        }
        ans = (ans + (S * x % mod + y * K % mod) % mod) % mod;
    }
    cout << ans << endl;
}