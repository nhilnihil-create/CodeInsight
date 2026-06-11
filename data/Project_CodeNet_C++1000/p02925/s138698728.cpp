#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int dfs(int n, vec<vec<int>> &from, vec<int> &c, vec<bool> &visited) {
    if (c[n] != -1) return c[n];
    if (visited[n]) return -1;
    visited[n]   = true;
    int tmpOrder = -1;
    for (auto e : from[n]) {
        int tmp = dfs(e, from, c, visited);
        if (tmp == -1) return -1;
        tmpOrder = max(tmpOrder, tmp + 1);
    }
    if (tmpOrder == -1)
        c[n] = 1;
    else
        c[n] = tmpOrder;
    return c[n];
}

int main() {
    int N;
    cin >> N;
    vec<vec<int>> A(N, vec<int>(N - 1));
    rep(i, N) rep(j, N - 1) {
        cin >> A[i][j];
        --A[i][j];
    }

    vec<vec<int>> gameid(N, vec<int>(N, -1));
    int now = 0;
    rep(i, N) rep(j, N) {
        if (i == j || i >= j) continue;
        gameid[i][j] = now;
        ++now;
    }

    vec<vec<int>> games(N, vec<int>(N - 1));
    rep(i, N) rep(j, N - 1) {
        int aa = i;
        int vs = A[i][j];
        if (aa > vs) swap(aa, vs);
        games[i][j] = gameid[aa][vs];
    }

    vec<vec<int>> from(now, vec<int>());
    rep(i, N) rep(j, N - 2) {
        from[games[i][j + 1]].push_back(games[i][j]);
    }

    vec<int> c(now, -1);
    vec<bool> visited(now, false);
    int ans = 0;
    rep(i, now) {
        int sortOrder = dfs(i, from, c, visited);
        if (sortOrder == -1) {
            cout << -1 << endl;
            return 0;
        }
        ans = max(ans, sortOrder);
    }

    cout << ans << endl;
}