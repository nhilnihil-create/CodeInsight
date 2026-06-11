#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    int N;
    cin >> N;
    vec<ll> A(N + 1), S(N + 1), M(N + 1);
    rep(i, N + 1) cin >> A[i];

    S[N] = A[N];
    for (int i = N - 1; i >= 0; --i)
        S[i] = S[i + 1] + A[i];

    rep(i, N + 1) {
        if (i == 0)
            M[i] = 1;
        else
            M[i] = min(M[i - 1] * 2, S[i]);
    }

    vec<ll> ans(N + 1);
    ll a = 0;
    rep(i, N + 1) {
        if (i == 0)
            ans[i] = M[i];
        else {
            ans[i] = min(M[i], (ans[i - 1] - A[i - 1]) * 2LL);
            ;
        }
        if (ans[i] < A[i]) {
            cout << -1 << endl;
            return 0;
        }
        a+=ans[i];
    }
    cout << a << endl;
}
