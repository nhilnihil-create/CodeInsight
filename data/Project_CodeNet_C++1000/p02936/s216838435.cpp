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
    ll N, Q;
    cin >> N >> Q;
    Graph G(N);
    rep(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<ll> score(N);
    rep(i, Q) {
        ll p, x;
        cin >> p >> x;
        p--;
        score[p] += x;
    }

    queue<ll> que;
    que.push(0);
    vector<bool> visit(N, false);
    visit[0] = true;
    while (que.size()) {
        ll now = que.front();
        que.pop();
        for (auto next : G[now]) {
            if (visit[next] == true) continue;
            visit[next] = true;
            score[next] += score[now];
            que.push(next);
        }
    }

    rep(i, N) {
        cout << score[i];
        if (i == N - 1)
            cout << "\n";
        else
            cout << " ";
    }
    return 0;
}