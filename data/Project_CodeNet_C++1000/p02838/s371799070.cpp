// 6/23 解き直し
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

const int mod = 1000000007;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    // mint sum = 0;
    // ll xsum;

    // // rep(i, N) sum += A[i];
    // // sum = sum * (N - 1) / 2;

    // xsum = A[0] ^ A[1];
    // sum = xsum;

    // for (int i = 2; i < N; i++) {
    //     sum = xsum + A[i];
    //     xsum ^= A[i];
    // }

    // cout << sum << endl;

    ll ans = 0;

    rep(i, 60) {
        ll x = 0;
        rep(j, N) if (A[j]>>i&1) ++x;
        ll now = x * (N - x) % mod;
        rep(j, i) now = now * 2 % mod;
        ans += now;
        ans %= mod;
    }
    cout << ans << endl;
}