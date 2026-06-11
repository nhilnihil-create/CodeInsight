#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
#define fr(i,k,n) for (int i = k; i < n; ++i)
#define fri(i,k,n) for (int i = k; i >= n; --i)
#define INF (int)1e9
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define all(arr) arr.begin(),arr.end()

void boost(){
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vi par;

int findpar(int u){
  if(par[u]==u)
    return u;
  return par[u]=findpar(par[u]);
}

void uni(int u,int v){
  par[findpar(u)]=par[findpar(v)];
}

void solve(){
  int n,q;
  cin>>n>>q;
  par.resize(n+1);
  iota(all(par),0);
  int t,u,v;
  while(q--){
    cin>>t>>u>>v;
    if(t==0){
      uni(u,v);
    }else{
      if(findpar(u)==findpar(v)){
        cout<<1<<endl;
      }
      else{
        cout<<0<<endl;
      }
    }
  }
  return;
}

int main()
{
  boost();
  
  int tc=1;
  //cin>>tc;
  while(tc--)
    solve();
  return 0;
}