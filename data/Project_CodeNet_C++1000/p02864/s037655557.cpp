#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#define mkp make_pair
#define mkt make_tuple
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
template<class T> void chmin(T &a,const T &b){if(a>b) a=b;}
template<class T> void chmax(T &a,const T &b){if(a<b) a=b;}

ll dp[303][303][303];
const ll INF=1e18;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N,K;
  cin>>N>>K;
  vector<ll> H(N);
  rep(i,N) cin>>H[i];

  rep(i,N+1) rep(j,K+1) rep(k,N+1) dp[i][j][k]=INF;
  dp[0][0][0]=0;
  for(int i=0;i<N;i++){
      for(int j=0;j<=K;j++){
          for(int k=0;k<=i;k++){
              if(dp[i][j][k]==INF) continue;
              ll preh=0;
              if(k>0) preh=H[k-1];
              {
                  ll neco=max(0ll,H[i]-preh);
                  chmin(dp[i+1][j][i+1],dp[i][j][k]+neco);
              }

              {
                  if(j+1<=K){
                      chmin(dp[i+1][j+1][k],dp[i][j][k]);
                  }
              }
          }
      }
  }

  ll ans=INF;
  rep(i,N+1) chmin(ans,dp[N][K][i]);
  cout<<ans<<endl;

  return 0;
}
