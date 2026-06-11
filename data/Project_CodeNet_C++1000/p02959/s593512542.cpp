#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; (i) < ((int)(n)); ++(i))

int main() {
    ll ans = 0;
    int N;
    cin >> N;
    vector<ll> A(N + 1), B(N);
    rep(i, N + 1) cin >> A[i];
    rep(i, N) cin >> B[i];
    rep(i, N) {
        ans += min(A[i], B[i]);
        B[i] = max(0LL, B[i] - A[i]);
        ans += min(A[i + 1], B[i]);
        A[i + 1] = max(0LL, A[i + 1] - B[i]);
    }

    cout << ans << endl;
}