#include <bits/stdc++.h>
using namespace std;

#define REP(i, start, count) for(int i=(start); i<(int)(count); ++i)
#define rep(i, count) REP(i, 0, count)
#define ALLOF(c) (c).begin(), (c).end()

using ll = long long;
using ull = unsigned long long;
using veci = vector<int>;
using vecll = vector<ll>;
using vecull = vector<ull>;

int main(void) {
    int N;
    cin >> N;
    vector<veci> G(N);
    vector<pair<int, int>> vp;

    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
        vp.emplace_back(a, b);
    }

    int cols_min = 0;
    map<pair<int, int>, int> ans;
    veci cs(N, 0);

    veci used(N, 0);
    queue<int> que;
    used[0] = 1;
    que.emplace(0);
    while(!que.empty()) {
        int v = que.front(); que.pop();

        cols_min = max(cols_min, (int)G[v].size());

        int cur = 1;

        for (int u : G[v]) {
            // 親がヒットしたらスキップ
            if (used[u]) continue;

            // 親と同じ色ならスキップ
            if (cur == cs[v]) cur++;

            // 次の色を塗る
            cs[u] = ans[make_pair(u, v)] = ans[make_pair(v, u)] = cur++;

            used[u] = 1;

            que.emplace(u);

        }
    }

    cout << cols_min << endl;
    for(auto p : vp) cout << ans[p] << endl;


    return 0;
}
