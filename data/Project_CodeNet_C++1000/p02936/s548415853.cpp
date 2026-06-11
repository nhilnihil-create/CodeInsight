#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define F first
#define S second

using namespace std;
typedef pair<int,int> P;

const int MOD=1000000007;
int INF=100100100100100;

vector<int> g[200010];
int in[200010];
int out[200010];
int imos[200010];
int ans[200010];
int k=0;
vector<int> jun;

void dfs(int v,int p=-1){
  jun.pb(v);
  in[v]=k;
  k++;
  for(int w:g[v]){
    if(w!=p){
      dfs(w,v);
    }
  }
  out[v]=k;
}
signed main(){
  int n,q;
  cin>>n>>q;
  rep(i,n-1){
    int a,b;
    cin>>a>>b;a--;b--;
    g[a].pb(b);
    g[b].pb(a);
  }
  
  dfs(0);

  rep(i,q){
    int p,x;
    cin>>p>>x;p--;
    imos[in[p]]+=x;
    imos[out[p]]-=x;
  }
  rep(i,n){
    if(i==0)ans[0]=imos[0];
    else ans[i]=ans[i-1]+imos[i];
    
  }
  rep(i,n){
    cout<<ans[in[i]]<<endl;
  }
    
  return 0;
}