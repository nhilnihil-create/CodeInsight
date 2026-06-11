#include <bits/stdc++.h>
#define exrep(i, a, b) for(long long i = a; i <= b; i++)
#define rep(i,n)for(long long i=0;i<(long long)(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 

  int n;
  cin >> n;
  vector<vector<P>> G(n);
  vl ans(n-1);
  rep(i,n-1){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(P(b,i));
    G[b].push_back(P(a,i));
  }
  queue<int>q;
  q.push(0);
  vector<int>used(n);
  used[0]=1;
  while(!q.empty()){
    int v = q.front(); q.pop();
    int c = -1;
    for(auto nv:G[v]){
      int next = nv.first, id=nv.second;
      if(used[next]) c=ans[id];
    }
    int k = 1;
    for(auto nv:G[v]){
      int next = nv.first, id=nv.second;
      if(used[next]) continue;
      if(k == c) k++;
      ans[id] = k;
      k++;
      q.push(next);
      used[next] = 1;
    }
  }
  
  
  int m=0;
  rep(i,n)m=max(m,(int)G[i].size());
  cout << m << endl;
  rep(i,n-1) cout<<ans[i] << endl;
  return 0;
  
}
