#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define vi vector<ll>
#define vvi vector<vi>
#define BITLE(n) (1LL<<((ll)n))
#define BITCNT(n) (__builtin_popcountll(n))
#define SUBS(s,f,t) ((s).substr((f)-1,(t)-(f)+1))
#define ALL(a) (a).begin(),(a).end()
using namespace std;
vi E[111111];
bool used[111111];
bool vis[111111][5];
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n,m;cin>>n>>m;
  for(int i=0;i<m;i++){
    ll u,v;cin>>u>>v;
    u--;v--;
    E[u].pb(v);
    //E[v].pb(u);
  }
  ll s,t;cin>>s>>t;
  s--;t--;
  used[s]=true;
  queue<pair<ll,ll>>que;
  que.push(mp(s,0));
  vis[s][0] = true;
  while(!que.empty()){
    ll now,cost;
    tie(now,cost) = que.front();
    que.pop();
    // cout<<now<<endl;
    //if(used[now]){
    //continue;
    //}
    queue<ll>que2;
    que2.push(now);
    for(int i=0;i<3;i++){
      ll r = que2.size();
      
      for(int j=0;j<r;j++){
	ll nx = que2.front();
	que2.pop();
	//	cout<<nx<<" "<<i+1<<" "<<now<<endl;

	//cout<<nx<<" "<<j+1<<" "<<vis[nx][j+1]<<endl;
	for(auto e:E[nx]){
	  if(vis[e][i+1])continue;
	  vis[e][i+1] = true;
	  que2.push(e);
	}
      }
    }

    while(!que2.empty()){
      ll nx = que2.front();
      que2.pop();
      if(nx == t){
	cout<<cost+1<<endl;
	return 0;
      }
      if(used[nx] == false){
	used[nx] = true;
	que.push(mp(nx,cost+1));
      }
    }
  }
  cout<<-1<<endl;
  return 0;
}
