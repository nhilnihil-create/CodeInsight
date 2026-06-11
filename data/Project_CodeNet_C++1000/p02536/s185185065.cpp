#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define i128 __int128
#define mp make_pair
#define ld long double
typedef pair<int, int> pii;
typedef priority_queue<int, vector<int>, greater<int> > small_heap;
typedef priority_queue<int> big_heap;
const int N = 1e6 + 100;
int T;
int n, m;

struct graph {
    int head[N], nxt[N << 1], to[N << 1], w[N << 1], sz;

    void init() { memset(head, 0, sizeof(head)), sz = 0; }

    graph() { init(); }

    void push(int a, int b, int c) {
        nxt[++sz] = head[a], to[sz] = b, w[sz] = c, head[a] = sz;
    }

    int &operator[](const int a) { return to[a]; }
} g;

int vis[N];

void dfs(int u) {
    vis[u] = 1;
    for (int i = g.head[u]; i; i = g.nxt[i]) {
        if (!vis[g[i]])dfs(g[i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g.push(a, b, 0);
        g.push(b, a, 0);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
            ans++;
        }
    }
    cout << ans-1;
    return 0;
}