// In god we trust
 
#include <bits/stdc++.h>
#include <chrono>
#include <algorithm>
#include <signal.h>
#include <thread>
 
#define pb push_back
#define fi first
#define se second
#define Vi vector<int>
#define Vb vector<bool>
#define Pi pair<int, int>
#define MP make_pair
#define MT make_tuple
#define INF 1000000000 
#define LINF 1000000000000000000
#define int long long
using namespace std;
using namespace std::chrono;
 
vector<Pi> g[500000];
int prohibit[500000];
int col[500000];
int k = 0;

void dfs(int v, int par = -1){
  Vi cols;
  for (int i = 0; i < g[v].size(); i++)
    if (i + 1 != prohibit[v])
      cols.pb(i + 1);

  int cnt = 0;
  for (int i = 0; i < g[v].size(); i++){
    if (g[v][i].fi != par){
      prohibit[g[v][i].fi] = cols[cnt];
      col[g[v][i].se] = cols[cnt++];
    }
  }
  for (auto i: g[v]){
    if (i.fi != par)
      dfs(i.fi, v);
  }
}
signed main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++){
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].pb({b, i});
    g[b].pb({a, i});
  }
  for (int i = 0; i < n; i++)
    k = max(k, (int)g[i].size());; 
  
  dfs(0);
  cout << k << endl;
  for (int i = 0; i < n - 1; i++)
    cout << col[i] << endl;
}
