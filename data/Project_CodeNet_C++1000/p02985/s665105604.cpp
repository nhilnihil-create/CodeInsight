#include <bits/stdc++.h>
using namespace std;

#define sz(x) int(x.size())
#define Task "abc"
#define For(i, a, b) for(int i = (a), _b = (b); i <= b; ++i)
#define All(x) (x).begin(), (x).end()
#define mp make_pair

typedef unsigned long long ull;
typedef long long ll;

const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;

int n, k;
ll ans = 1;
vector<int> g[maxn];

void dfs(int u, int par, int col){
  int haveCol = k;

  ans = (ans * col) % mod;

  if (par == -1) --haveCol;
  else haveCol -= 2;

  haveCol = max(0, haveCol);

  for (int i = 0; i < g[u].size(); ++i){
    int v = g[u][i];
    if (v == par) continue;
    dfs(v, u, haveCol);
    --haveCol;
    haveCol = max(0, haveCol);
  }

}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
//  freopen(Task".inp", "r", stdin); freopen(Task".out", "w", stdout);
  cin >> n >> k;

  for (int i = 1; i < n; ++i){
    int u, v; cin >> u >> v;
    g[u].push_back(v); g[v].push_back(u);
  }

  dfs(1, -1, k);
  cout << ans;
return 0;
}

