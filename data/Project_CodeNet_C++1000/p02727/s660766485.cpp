#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
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

int main () {
  int X,Y,A,B,C;cin>>X>>Y>>A>>B>>C;
  priority_queue<P> pq;
  rep(i,A) {
    ll p;cin>>p;
    pq.push(P(p,0));
  }
  rep(i,B) {
    ll q;cin>>q;
    pq.push(P(q,1));
  }
  rep(i,C) {
    ll r;cin>>r;
    pq.push(P(r,2));
  }
  int red = 0, green = 0, sum = 0;
  ll deli = 0;
  while(sum < X + Y) {
    ll d = pq.top().first;
    int typ = pq.top().second;
    pq.pop();
    if(typ == 0) {
      if(red < X) {
	red++;
	sum++;
	deli += d;
      }
    } else if(typ == 1) {
      if(green < Y) {
	green++;
	sum++;
	deli += d;
      }
    } else {
      sum++;
      deli += d;
    }
  }
  cout << deli << endl;
}
