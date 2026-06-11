#include <bits/stdc++.h>

#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;

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
    const ll limit = pow(10, 18);
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) { cin >> A[i]; }

    sort(all(A));

    cpp_int ans = 1;
    rep(i, N) {
        ans *= A[i];
        if (ans > limit) {
            ans = -1;
            break;
        }
    }
    cout << ans << endl;
}