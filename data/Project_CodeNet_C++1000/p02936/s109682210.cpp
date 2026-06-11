#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define chmin(a,b) if((a)>(b)) (a)=(b);
#define chmax(a,b) if((a)<(b)) (a)=(b);
#define vi vector<int>
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define pb push_back
#define pf push_front
int gcd(int a,int b){/*a>=0,b>=0,￢(a=b=0)*/
  while(min(a,b)>0){if(a<b)swap(a,b);a%=b;}return max(a,b);
}
int dx[]={1,0,-1,0,1,-1,-1,1};
int dy[]={0,1,0,-1,1,1,-1,-1};
const int MOD = 1e9+7;
const int INF = 1e18+10;

/*----------------------------------------------*/
vi to[200200];
int cnt[200200];

void dfs(int v,int p=-1){
  for(int u:to[v]){
    if(u==p) continue;
    cnt[u]+=cnt[v];
    dfs(u,v);
  }
}

signed main(){
  int n,q;
  cin>>n>>q;
  rep(i,n-1){
    int a,b;
    cin>>a>>b;
    a--;b--;
    to[a].pb(b);
    to[b].pb(a);
  }
  rep(i,q){
    int p,x;
    cin>>p>>x;
    p--;
    cnt[p]+=x;
    // dfs(p);
  }
  dfs(0,-1);
  rep(i,n){
    cout<<cnt[i];
    if(i<n-1) cout<<" ";
  }
  cout<<endl;

  return 0;
}
