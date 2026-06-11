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

int main(){
  string S;cin>>S;
  int N = S.size();
  reverse(S.begin(),S.end());
  S += '0';
  ll ans = 0;
  bool dig = false;
  rep(i,N+1){
    int now = S[i] - '0';
    if(dig) now++;
    dig = false;
    int nxt = 0;
    if(i+1 <= N) nxt = S[i+1] - '0';
    if(now > 5 || (now == 5 && nxt >= 5)) {
      ans += 10 - now;
      dig = true;
    } else {
      ans += now;
    }
  }
  cout<<ans<<endl;
}
