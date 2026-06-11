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
constexpr ll mod = 1000000007;

int main() {
    int N;
    cin >> N;
    vector<uint64_t> A(N);
    rep(i, N) { cin >> A[i]; }
    uint64_t all = 0;
    rep(i, N) { all ^= A[i]; }

    vector<uint64_t> ans;

    rep(i, N) {
        uint64_t num;
        num = A[i] ^ all;
        ans.emplace_back(num);
    }

    rep(i, ans.size() - 1) { cout << ans[i] << " "; }
    cout << ans[ans.size() - 1] << endl;
}