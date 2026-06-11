#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define MAX 200005
#define INF 1001001001

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

vector<int> to[200005];
  vector<int> pls(200005);
  vector<int> ans(200005);

void dfs(int v, int p=-1) {
  if(p==-1){
    ans[v]=pls[0];
  } else{
    ans[v]=pls[v]+ans[p];
  }
  for (int u : to[v]) {
    if (u == p) continue;
    dfs(u,v);
  }
}

int main(){
  int n, q;
  cin >> n >> q;
  rep(i,n-1) {
      int a, b;
      cin >> a >> b;
      --a; --b;
      to[a].push_back(b);
      to[b].push_back(a);
    }
  rep(i, q){
    int p, x;
    cin >> p >> x;
    p--;
    pls[p]+=x;
  }
  dfs(0);
  rep(i, n){
    cout << ans[i] << endl;
  }
  return 0;
}
