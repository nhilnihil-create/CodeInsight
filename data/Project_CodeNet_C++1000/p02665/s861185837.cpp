#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int N;
    cin >> N;
    vec<ll> A(N + 1), S(N + 2);
    rep(i, N + 1) cin >> A[i];

    for (int i = N; i >= 0; --i) {
        S[i] = S[i + 1] + A[i];
    }

    ll ans  = 0;
    ll next = 1;
    rep(i, N + 1) {
        ans += next;
        next -= A[i];
        if (next < 0) {
            cout << -1 << endl;
            return 0;
        }
        next = min(next * 2, S[i + 1]);
    }
    cout << ans << endl;
}
