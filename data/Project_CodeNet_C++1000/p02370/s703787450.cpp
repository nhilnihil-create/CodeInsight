#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
#include <iostream>
#include <string>
#include <bitset>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

#define ALL(g) (g).begin(), (g).end()
#define REP(i, x, n) for(int i = x; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define INF 1 << 30
#define pb push_back
#define mp make_pair

typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef long long ll;

static const int MAX = 100000;


vector<int> G[MAX];
vector<int> out;
int V[MAX];
int N;
int indeg[MAX];

void bfs(int s) {
    queue<int> q;
    q.push(s);
    V[s] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        out.push_back(u);

        rep(i, G[u].size()) {
            int v = G[u][i];
            indeg[v]--;
            if (indeg[v] == 0 && V[v] == 0) {
                V[v] = 1;
                q.push(v);
            }
        }
    }
}


void tsort(void) {
    rep(i, N) {
        V[i] = 0;
        indeg[i] = 0;
    }

    rep(i, N) {
        rep(j, G[i].size()) {
            indeg[G[i][j]]++;
        }
    }

    rep(i, N) {
        if (indeg[i] == 0 && V[i] == 0) bfs(i);
    }
}


int main(void) {
    int M, s, t;
    scanf("%d %d", &N, &M);

    rep(i, M) {
        scanf("%d %d", &s, &t);
        G[s].push_back(t);
    }

    tsort();

    rep(i, out.size()) printf("%d\n", out[i]);

    return 0;
}