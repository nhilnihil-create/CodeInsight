#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
struct edge { ll s, t, x; };
typedef pair<int, int> P;
typedef pair<ll,P> event;
const ll MAX = 510000;
const ll MOD = 1000000007;
#define INF (ll)1000000000000

ll ans=1ll;
ll N,K;
vector<vector<int>>Ki(100000);

void dfs(int now,int par){
  ll g=K;
  if(par==0&&now==0){ans*=K;}
  else{g--;}
  for(auto t:Ki[now]){
    if(t==par){continue;}
    g--;
    ans*=g;
    ans%=MOD;
    dfs(t,now);
  }
  return;
}

int main() {
  cin>>N>>K;
  rep(i,N-1){
    int a,b;cin>>a>>b;a--;b--;
    Ki[a].push_back(b);
    Ki[b].push_back(a);
  }
  dfs(0,0);
  cout<<ans;
}
