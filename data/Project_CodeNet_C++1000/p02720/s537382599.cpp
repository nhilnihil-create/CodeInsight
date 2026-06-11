#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define P pair<ll, ll>
#define Graph vector<vector<ll>>
#define fi first
#define se second
constexpr ll mod = 1000000007;
constexpr ll INF = (1ll << 60);
constexpr double pi = 3.14159265358979323846;
template <typename T>
inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T>
inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    ll K;
    cin >> K;
    queue<ll> que;
    rep(i, 10) {
        if (i == 0) continue;
        que.push(i);
    }

    ll cnt = 0;
    while (1) {
        ll now = que.front();
        que.pop();
        cnt++;
        if (cnt == K) {
            cout << now << "\n";
            return 0;
        }

        if (now % 10 != 0) que.push(now * 10 + now % 10 - 1);
        que.push(now * 10 + now % 10);
        if (now % 10 != 9) que.push(now * 10 + now % 10 + 1);
    }

    return 0;
}