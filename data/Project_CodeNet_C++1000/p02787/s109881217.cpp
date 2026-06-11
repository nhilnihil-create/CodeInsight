#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<double,int> PP;
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
  int H,N;cin>>H>>N;
  vector<int> a(N),b(N);
  rep(i,N) cin>>a[i]>>b[i];
  vector<ll> dp(H+10010,INF);
  dp[0] = 0;
  rep(i,N) {
    rep(j,H+1) {
      chmin(dp[j+a[i]],dp[j]+b[i]);
    }
  }
  ll ans = INF;
  for(int i = H;i<(int)dp.size();i++) {
    chmin(ans,dp[i]);
  }
  cout<<ans<<endl;
}