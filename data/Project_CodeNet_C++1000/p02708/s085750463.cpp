#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define RREP(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i <= (ll)(b); i++)
#define RFOR(i, a, b) for (ll i = a; i >= (ll)(b); i--)
#define ALL(x) (x).begin(), (x).end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    os << "[ ";
    for (auto a : v) os << a << " ";
    os << "]";
    return os;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<ll> L(N + 1), R(N + 1);
    R[0] = N;
    REP(i, N) {
        L[i + 1] = L[i] + (i + 1);
        R[i + 1] = R[i] + (N - i - 1);
    }

    ll mod = 1e9 + 7;
    ll ans = 0;
    FOR(k, K, N + 1) ans = (ans + (R[k - 1] - L[k - 1] + 1)) % mod;

    // cout << L << endl;
    // cout << R << endl;
    cout << ans << endl;
    return 0;
}