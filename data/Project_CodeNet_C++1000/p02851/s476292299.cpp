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
  int N,K;cin>>N>>K;
  vector<int> a(N);
  rep(i,N) cin>>a[i];
  vector<int> s(N+1,0);
  map<int,vector<int>> dic;
  dic[0].push_back(0);
  rep(i,N) {
    s[i+1] = (s[i] + a[i]) % K;
    // cout<<s[i+1]<<endl;
  }
  rep(i,N) {
    dic[((s[i+1] - (i+1)) % K + K) % K].push_back(i+1);
  }
  ll ans = 0;
  for(auto it = dic.begin();it!=dic.end();++it) {
    if(it->second.size() < 2) continue;
    int cnt = 0;
    for(auto now : it->second) {
      int plc = lower_bound(it->second.begin(),it->second.end(),now+K) - it->second.begin();
      ans += plc - 1 - cnt;
      // cout<<it->first<<" "<<now<<" "<<plc<<" "<<cnt<<" "<<ans<<endl;
      cnt++;
    }
  }
  cout<<ans<<endl;
}
