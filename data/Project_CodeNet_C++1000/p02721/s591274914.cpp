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
  int N,K,C;cin>>N>>K>>C;
  string S;cin>>S;
  vector<P> issame(K);
  int i = 0,cnt = 0;
  while(cnt < K) {
    if(S[i] == 'o') {
      issame[cnt].first = i;
      i += C + 1;
      cnt++;
    } else {
      i++;
    }
  }
  reverse(S.begin(),S.end());
  cnt = 0;
  i = 0;
  while(cnt < K) {
    if(S[i] == 'o') {
      issame[K - cnt - 1].second = N - i -1;
      i += C + 1;
      cnt++;
    } else {
      i++;
    }
  }
  for(auto pir : issame) {
    //    cout << pir.first << " " << pir.second << endl;
    if(pir.first == pir.second) {
      cout << pir.first + 1 << endl;
    }
  }
}
