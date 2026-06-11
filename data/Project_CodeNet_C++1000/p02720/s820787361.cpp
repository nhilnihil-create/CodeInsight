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
  int K;cin>>K;
  if(K <= 9) {
    cout << K << endl;
    return 0;
  }
  int cnt = 0;
  queue<ll> qu;
  rep(i,9){
    qu.push(i+1);
  }
  while(1) {
    ll now = qu.front();
    qu.pop();
    cnt++;
    if(cnt == K) {
      cout << now << endl;
      return 0;
    }
    ll last = now % 10;
    if(last == 0) {
      qu.push(now * 10);
      qu.push(now * 10 + 1);
    } else if(last == 9) {
      qu.push(now * 10 + 8);
      qu.push(now * 10 + 9);
    } else {
      rep(i,3) {
	qu.push(now * 10 + (last - 1 + i));
      }
    }
  }
}
