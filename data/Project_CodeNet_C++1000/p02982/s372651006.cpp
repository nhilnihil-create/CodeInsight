#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define pi 3.14159265359
#define all(i) i.begin(),i.end()
using namespace std;
const long long INF=1e9+7;
const string alp="abcdefghijklmnopqrstuvwxyz"; //26
const string ALP="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
//const ll MOD=998244353LL;
//const ll MOD=1777777777LL;
 
 
int main() {
  ll N,D;
  cin>>N>>D;
  ll x[N][D];
  rep(i,N){
    rep(j,D){
      cin>>x[i][j];
    }
  }
  ll ans=0;
  ll dist=0;
  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
      for(int k=0;k<D;k++){
        dist+=(x[i][k]-x[j][k])*(x[i][k]-x[j][k]);
      }
      for(int k=1;k<=dist;k++){
        if(k*k==dist){
          ans++;
          dist=0;
          break;
        }
      }
      dist=0;
    }
  }
  cout<<ans<<endl;
}