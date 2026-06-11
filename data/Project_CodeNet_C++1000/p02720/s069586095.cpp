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

ll dp[10][100];

int main() {
    ll K;
    cin >> K;


    ll tmp;
    queue<ll> que;

    for (ll i = 1; i < 10; ++i) {
        que.emplace(i);
    }
    for (int i = 0; i < K; ++i) {
        tmp = que.front();
        que.pop();

        if (tmp % 10 != 0)
        {
            que.emplace(10 * tmp + tmp % 10 - 1);
        }

        que.emplace(10 * tmp + tmp % 10);

        if (tmp % 10 != 9) {
            que.emplace(10 * tmp + tmp % 10 + 1);
        }
    }

    cout << tmp << endl;
}