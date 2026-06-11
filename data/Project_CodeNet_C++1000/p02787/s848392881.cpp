#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n) ;i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using ll=long long;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MOD  1000000007
const ll INF=1e18;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b){ a = b; return 1; } return 0; }



int main(int argc, char const *argv[]) {
  int n,h;
  cin >> h >> n;
  vector<int> a(n),b(n);
  vector<vector<ll>> dp(n+1,vector<ll>(h+1,INF));
  dp[0][0]=0;
  rep(i,n){
    cin >> a[i] >> b[i];
  }
  rep(i,n){
    for(int j=0; j<=h; j++){
      //dp[i+1][j]=min(dp[i][j],dp[i+1][j-a[i]]+b[i]);

      chmin(dp[i+1][j], dp[i][j]);
      chmin(dp[i+1][min(j+a[i], h)], dp[i+1][j] + b[i]);

    }
  }

  cout << dp[n][h] << endl;

  return 0;
}
