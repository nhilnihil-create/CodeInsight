#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()


using namespace std;

typedef long long ll;

static const long long MOD = 1000000007;
static const long long INF = 1000000000;

int n;
ll ans = 1, k, d[100005];
vector<int> g[100005];

void bfs() {
    queue<int> q;
    rep(i, 1, 100005) d[i] = INF;
    d[1] = k;
    int c = k-1;
    for (int x : g[1]) {
        d[x] = c--;
        q.push(x);
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        int c = k-2;
        for (int v : g[u]) {
            if (d[v]==INF) {
                d[v] = c--;
                q.push(v);
            }
        }
    }


}

int main(void) {
    cin >> n >> k;
    rep(i, 0, n-1) {
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].pb(b);
        g[b].pb(a);
    }
    bfs();

    rep(i, 1, n+1) {
        ans *= d[i];
        ans %= MOD;
    }

    cout << ans % MOD << endl;

	return 0;
}
