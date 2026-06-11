#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const string EMP = " ";
const ll INF = 1LL<<60;
const ll MOD = 1000000007;
const double PI = acos(-1);

int n,m,q,ans = 0;
vector<int> a,b,c,d;

int chk(vector<int> g){
  int tt = 0;
  for(int i = 0; i < q; i++){
    if(g[b[i]] - g[a[i]] == c[i]) tt += d[i];
  }
  return tt;
}

void dfs(vector<int> g){
  if(g.size() == n){
    int now = chk(g);
    ans = max(ans, now);
    return;
  }
  for(int i = g.back(); i <= m; i++){
    g.push_back(i);
    dfs(g);
    g.pop_back();
  }
}

int main(){
  cin >> n >> m >> q;
  a.resize(q);
  b.resize(q);
  c.resize(q);
  d.resize(q);
  for(int i = 0; i < q; i++){
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    a[i]--; b[i]--;
  }
  vector<int> g;
  g.push_back(1);
  dfs(g);
  cout << ans << endl;
  return 0;
}
