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
    ll N, K, C;
    cin >> N >> K >> C;
    string S;
    cin >> S;

    vector<ll> forward(K);
    vector<ll> reverse(K);

    ll cnt = 0;
    for (ll i = 0; i < N; ++i) {
        if (S[i] == 'o') {
            forward[cnt] = i;
            ++cnt;

            if (cnt == K) break;

            i += C;
        }
    }

    cnt = K - 1;
    for (ll i = N - 1; i >= 0; --i) {
        if (S[i] == 'o') {
            reverse[cnt] = i;
            --cnt;

            if (cnt == -1) break;
            i -= C;
        }
    }

    for (ll i = 0; i < K; ++i) {
        if (forward[i] == reverse[i]) {
            cout << forward[i] + 1 << endl;
        }
    }
}