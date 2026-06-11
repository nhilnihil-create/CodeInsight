#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=2*asin(1);

ll N, K;
vector<vector<int> > edge(100005);

ll anstree[100005];

void solve(int v, int u){
  ll num = 0;
  if(u==-1){
    for(ll i=0;i<edge[v].size();++i){
      if(edge[v][i]==u) continue;
      anstree[edge[v][i]] = K-1-num;
      num++;
      solve(edge[v][i], v);
    }
  }
  else{
    for(ll i=0;i<edge[v].size();++i){
      if(edge[v][i]==u) continue;
      anstree[edge[v][i]] = K-2-num;
      num++;
      solve(edge[v][i], v);
    }
  }
}

int main() {
  cin>>N>>K;
  int a, b;
  for(int i=0;i<N-1;++i){
    cin>>a>>b;
    a--;
    b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  anstree[0] = K;
  solve(0, -1); 
  ll ans = 1;
  for(int i=0;i<N;++i){
    ans *= anstree[i];
    ans %= mod;
  }
  cout<<ans<<endl;
}

