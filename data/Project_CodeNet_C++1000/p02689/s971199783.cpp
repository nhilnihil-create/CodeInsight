#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const ll INFS=1e18;
const int MOD=INF+7;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};
const double PI=acos(-1);

int main() {
  int n,m;
  cin>>n>>m;
  vector<int> h(n);
  rep(i,n) cin>>h[i];
  vector<bool> ja(n,true);
  rep(i,m){
    int a,b;
    cin>>a>>b;
    a--;
    b--;
    if(h[a]==h[b]){
      ja[a]=false;
      ja[b]=false;
    }
    if(h[a]<h[b]){
      ja[a]=false;
    }
    if(h[a]>h[b]){
      ja[b]=false;
    }
  }
  int ans=0;
  rep(i,n){
    if(ja[i]) ans++;
  }
  cout<<ans<<endl;
}