#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> A(N + 1);
    for (int i = 0; i < N + 1; ++i) cin >> A[i];
    if (N < 63 && (ll)A[N] > (1ll << N)) {
        cout << -1 << endl;
        return 0;
    }
    vector<ll> ma(N + 1), mi(N + 1);
    ma[N] = A[N];
    mi[N] = A[N];
    for (int i = N; i > 0; --i) {
        mi[i - 1] = max(1ll, (mi[i] + 1) / 2 + A[i - 1]);
        ma[i - 1] = ma[i] + A[i - 1];
        if (i < 63) ma[i - 1] = min(ma[i - 1], 1ll << (i - 1));
        if (mi[i - 1] > ma[i - 1]) {
            cout << -1 << endl;
            return 0;
        }
    }
    ll ans = 1;
    ll x = 1;
    for (int i = 1; i < N + 1; ++i) {
        x = min(x * 2, ma[i]);
        if (x < mi[i]) {
            ans = -1;
            break;
        }
        ans += x;
        x -= A[i];
    }
    cout << ans << endl;
}