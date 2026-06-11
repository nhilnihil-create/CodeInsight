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
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i, N) {
        ll num;
        cin >> num;
        --num;
        A[i] = num;
    }

    vector<ll> is_visited(N, -1);
    ll cur = 0;
    for (ll i = 0; i < K; ++i) {
        cur = A[cur];
        if (is_visited[cur] != -1) {
            ll aaa = (K - 1 - i) / (i - is_visited[cur]);
            i += (i - is_visited[cur]) * aaa;
        }
        is_visited[cur] = i;
    }
    cout << cur + 1 << endl;
}