#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
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
  int N;cin>>N;
  vector<ll> a(N);
  rep(i,N) cin>>a[i];
  vector<vector<ll>> dig(65,vector<ll>(N+1,0));
  rep(i,60){
    rep(j,N) {
      int one = ((a[j]>>i)&1) ? 1 : 0;
      dig[i][j+1] = dig[i][j] + one;
    }
  }
  ll ans = 0;
  ll two = 1;
  rep(i,60) {
    ll cnt = 0;
    rep(j,N-1) {
      ll num = (dig[i][N] - dig[i][j+1] + MOD) % MOD;
      // cout<<i<<" "<<j<<" "<<num<<endl;
      if((a[j]>>i)&1) {
	cnt = (cnt + (N - (j+1) - num + MOD) % MOD) % MOD;
      } else {
	cnt = (cnt + num) % MOD;
      }
    }
    ans = (ans + (two * cnt) % MOD) % MOD;
    two = (two * 2) % MOD;
    //    cout<<i<<" "<<cnt<<" "<<ans<<endl;
    //cout<<endl;
  }
  cout<<ans % MOD <<endl;
}
