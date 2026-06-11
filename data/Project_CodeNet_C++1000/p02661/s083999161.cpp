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
    ll N;
    cin >> N;
    vector<ll> A(N), B(N);
    rep(i, N) {
        ll a, b;
        cin >> a >> b;
        A[i] = a;
        B[i] = b;
    }
    sort(all(A));
    sort(all(B));
    if (N % 2 == 1) {
        cout << B[N / 2] - A[N / 2] + 1 << endl;
    } else {

        cout << ((B[N / 2] + B[N / 2 - 1]) - (A[N / 2] + A[N / 2 - 1])) + 1
             << endl;
    }
}