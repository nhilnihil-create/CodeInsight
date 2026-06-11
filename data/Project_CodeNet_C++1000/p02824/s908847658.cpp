#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

int main() {
    ll N, M, V, P;
    cin >> N >> M >> V >> P;
    vector<ll> A(N), s(N + 1, 0);
    rep(i, N) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    rep(i, N) {
        s[i + 1] = s[i] + A[i];
    }
    ll lo = 0, hi = N;
    while (lo + 1 < hi) {
        ll mi = (lo + hi) / 2;
        if (mi > N - P) {
            hi = mi;
            continue;
        }
        if (A[mi - 1] + M < A[N - P]) {
            lo = mi;
            continue;
        }
        if (V <= P - 1 + mi) {
            hi = mi;
            continue;
        }
        ll s2 = s[N - P + 1] - s[mi] + M * max(0LL, V - P + 1 - mi);
        if (s2 <= (A[mi - 1] + M) * (N - P + 1 - mi)) hi = mi;
        else lo = mi;
    }
    cout << N - hi + 1 << "\n";
}