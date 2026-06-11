#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

int main() {
    int N, P;
    string S;
    cin >> N >> P >> S;
    if (P == 2 || P == 5) {
        ll ans = 0;
        rep(i, N) {
            if ((S[i] - '0') % P == 0) ans += i + 1;
        }
        cout << ans << "\n";
        return 0;
    }
    vector<int> a(N, 1), b(N + 1, 0), r(P, 0);
    rep(i, N - 1) a[N - 2 - i] = (a[N - 1 - i] * 10) % P;
    rep(i, N) b[i + 1] = (b[i] + (S[i] - '0') * a[i]) % P;
    rep(i, N + 1) r[b[i]]++;
    ll ans = 0;
    rep(i, P) {
        ans += 1LL * r[i] * (r[i] - 1) / 2;
    }
    cout << ans << "\n";
}