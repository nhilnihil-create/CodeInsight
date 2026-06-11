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

ll cal(ll a, ll b, ll x) {
    return (a * x  / b) - (a * (x / b));
}

int main() {
    ll A, B, N;
    cin >> A >> B >> N;
    if (B - 1 <= N) {
        cout << cal(A, B, B - 1) << endl;
    } else {
        cout << cal(A, B, N) << endl;
    }
}