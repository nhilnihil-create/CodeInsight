#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pll = pair<ll, ll>;

#define rep(i, n) for (ll i = 0, xxx_rep_end = (n); i < xxx_rep_end; ++i)
#define all(x) (x).begin(), (x).end()

template <class T1, class T2>
inline void chmax(T1 &a, const T2 &b) {
    if (a < b) a = b;
}
template <class T1, class T2>
inline void chmin(T1 &a, const T2 &b) {
    if (a > b) a = b;
}

constexpr ll INF = 0x3f3f3f3f3f3f3f3fLL;

int main() {
    ll N;
    cin >> N;
    ll dig = ceil(log(N * 25.0 / 26.0 + 1) / log(26.0));

    string ans;
    N -= (pow(26, dig - 1) - 1) * 26 / 25 + 1;
    for (ll i = 0; i < dig; ++i) {
        ll mod = N % 26;
        N /= 26;

        ans = (char)(mod + 97) + ans;
    }
    cout << ans << endl;
}