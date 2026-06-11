#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); ++i)
#define outl(x) cout<< (x) << '\n'
#define fi first
#define se second
using pii = pair<int,int>;
using ll = long long;
using vi = vector<int>;

int V, E;
vi G[100010];
int indeg[100010];
bool used[100010];

void bfs(int u, vi &ans)
{
    queue<int> que;
    que.push(u);

    ans.push_back(u);
    used[u] = true;

    while ( !que.empty() ) {
        int u = que.front(); que.pop();
        for (const auto &e : G[u]) {
            --indeg[e];
            if (indeg[e]==0 && !used[e]) {
                used[e] = true;
                ans.push_back(e);
                que.push(e);
            }
        }
    }

    return;
}

void topologicalSort(vi &ans)
{
    memset(indeg, 0, sizeof(indeg));
    memset(used, false, sizeof(used));
    ans.reserve(V+1);

    rep(i, V) {
        for (const auto &to : G[i]) {
            ++indeg[to];
        }
    }

    rep(i, V) {
        if (indeg[i] == 0 && !used[i]) bfs(i, ans);
    }
    return;
}


int main()
{
    vi ans;
    cin.tie(0), ios::sync_with_stdio(false);

    cin >> V>> E;

    rep(i, E) {
        int s, t;
        cin >> s >> t;
        G[s].push_back(t);
    }

    topologicalSort(ans);

    for (const auto &e: ans)
        outl(e);

    return (0);
}


