#include <bits/stdc++.h>
 
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
 
using namespace std;
 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;


vector<bool> visited(100000+1,0);
vector<int> graph[100000+1];

void dfs(int node) {
    visited[node] = true;
    for (int next_node : graph[node]) {
        if (!visited[next_node]) {
            dfs(next_node);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,u,v;
    cin >> n >> m;
    forn(i,m) {
        cin >> u >> v;
        graph[u-1].pb(v-1);
        graph[v-1].pb(u-1);
    }
    int ans = -1;
    forn(i,n) {
        if (!visited[i]) {
            dfs(i);
            ans++;
        }
    }
    cout << ans;
    return 0;
} 