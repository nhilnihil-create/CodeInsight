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

int x[100],y[100]; 
map<P,int> iti;
vector<P> edge;
signed main(){
  int n;cin>>n;
  int ans=n;
  rep(i,n){
    cin>>x[i]>>y[i];
    iti[P(x[i],y[i])]++;
  }
  rep(i,n){
    rep(j,n){
      if(i==j)continue;
      edge.pb(P(x[i]-x[j],y[i]-y[j]));
    }
  }
  
  for(auto e:edge){
    int res=0;
    rep(i,n){
      res++;
      if(iti[P(x[i]+e.F,y[i]+e.S)]>=1)res--;
    }
    ans=min(ans,res);
  }
  
  cout<<ans<<endl;
  return 0;
}