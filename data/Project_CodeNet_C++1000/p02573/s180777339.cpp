#include <bits/stdc++.h>
/*#ifndef LOCAL_RUN
    #pragma GCC optimize("Ofast")
    #pragma GCC optimize("unroll-loops")
    #pragma GCC optimize("fast-math")
    #pragma GCC target("avx2,tune=native")
#endif*/
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int N = 2e5+228;

vector<int> graph[N];
bool used[N];
int sz;

void dfs(int v)
{
    ++sz;
    used[v] = true;
    for (int u: graph[v]) {
        if (used[u]) continue;
        dfs(u);
    }
}

int main()
{
    #ifdef LOCAL_RUN
        freopen("input.txt", "r", stdin);
    //#else
        //freopen("cowcode.in", "r", stdin);
        //freopen("cowcode.out", "w", stdout);
    #endif
	ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            sz = 0;
            dfs(i);
            ans = max(ans, sz);
        }
    }
    cout << ans;

    return 0;
}

// 272472LF
