#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
const int MOD = 1000000000+7;
#define rev(s) (string((s).rbegin(), (s).rend()))
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
// cout << fixed << setprecision(10) << ans << endl;
// *min_element(c + l, c + r) *max_element(c + l, c + r)
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// struct Edge {
//   int to, id;
//   Edge(int to, int id): to(to), id(id) {}
// };

int main() {
  int N,M;cin>>N>>M;
  vector<int> a(M),open(M,0);
  rep(i,M) {
    cin>>a[i];
    int b;cin>>b;
    int can = 0;
    rep(j,b) {
      int c;cin>>c;
      c--;
      can |= (1<<c);
    }
    open[i] = can;
  }
  vector<vector<ll>> dp(M+1,vector<ll>((1<<N),INF));
  dp[0][0] = 0;
  rep(i,M) {
    rep(j,(1<<N)) {
      dp[i+1][j] = min(dp[i+1][j],dp[i][j]);
      dp[i+1][j|open[i]] = min(dp[i+1][j|open[i]],dp[i][j]+a[i]);
    }
  }
  // rep(i,M+1) {
  //   rep(j,1<<N) {
  //     cout<<dp[i][j]<<" ";
  //     if(j==(1<<N)-1) cout<<endl;
  //   }
  // }
  if(dp[M][(1<<N)-1] < INF) {
    cout<<dp[M][(1<<N)-1]<<endl;
  } else {
    cout<<-1<<endl;
  }
}
