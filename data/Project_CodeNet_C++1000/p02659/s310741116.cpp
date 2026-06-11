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
    uint64_t A;
    string B;
    cin >> A >> B;

    uint64_t BB = 0;
    BB += (B[0] - '0') * 100;
    if (B.size() >= 3) BB += (B[2] - '0') * 10;
    if (B.size() >= 4) BB += B[3] - '0';

    uint64_t ans = A * BB / 100;

    cout << ans << endl;
}