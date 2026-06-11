#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define BITLE(n) (1LL<<((ll)n))
#define SHIFT_LEFT(n) (1LL<<((ll)n))
#define SUBS(s,f,t) ((s).substr((f)-1,(t)-(f)+1))
#define ALL(a) (a).begin(),(a).end()
using namespace std;

ll n,k;
vvi E(111111);
ll dp[111111];

ll dfs(ll now, ll par,ll num){
  ll kake = 1,minus=0;
  if(par != -1)minus++;
  for(auto e:E[now]){
    if(e == par)continue;
    kake *= (dfs(e, now, k-minus-1))%MOD;
    //cout<<e<<" "<<now<<" "<<k-minus<<endl;
    kake %= MOD;
    minus++;
  }
  //    cout<<now<<" "<<par<<" "<<kake<<endl;
  return (dp[now] = max(0LL,(kake*num)%MOD));
}
int main(){
  cin>>n>>k;
  for(int i = 0;i < n-1;i++){
    ll a,b;cin>>a>>b;
    a--;b--;
    E[a].pb(b);
    E[b].pb(a);
  }
  cout<<dfs(0,-1,k)<<endl;
  return 0;
}
