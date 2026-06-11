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
  int N,M;cin>>N>>M;
  string S;cin>>S;
  int now = N;
  vector<int> can;
  rep(i,N+1) {
    if(S[i]=='0') can.push_back(i);
  }
  vector<int> ans;
  while(1) {
    if(now-M<=0) {
      ans.push_back(now);
      break;
    } else {
      int plc = lower_bound(can.begin(),can.end(),now-M) - can.begin();
      if(can[plc]==now) {
	cout<<-1<<endl;
	return 0;
      } else {
	ans.push_back(now-can[plc]);
	now = can[plc];
      }
    }
  }
  rep(i,(int)ans.size()) cout<<ans[(int)ans.size()-1-i]<<" ";
  cout<<endl;
}
