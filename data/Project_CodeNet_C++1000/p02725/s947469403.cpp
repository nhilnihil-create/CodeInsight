#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pll = pair<ll, ll>;

#define rep(i, n) for (ll i = 0, xxx_rep_end = (n); i < xxx_rep_end; ++i)
#define all(x) (x).begin(), (x).end()

template <class T1, class T2>
inline bool chmax(T1 &a, const T2 &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T1, class T2>
inline bool chmin(T1 &a, const T2 &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

constexpr ll INF = 0x3f3f3f3f3f3f3f3fLL;
constexpr ll mod = 1000000007;

int main() {
    ll K, N;
    cin >> K >> N;
    vector<ll> A(N);
    rep(i, N) { cin >> A[i]; }

    ll dist = 0;
    for (int i = 0; i < N - 1; ++i) {
        ll tmp = A[i + 1] - A[i];
        chmax(dist, tmp);
    }

    chmax(dist, A[0] + K - A[N - 1]);

    cout << K - dist << endl;
}