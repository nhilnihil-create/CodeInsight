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

int main () {
  string S;cin>>S;
  int N = S.size();
  reverse(S.begin(),S.end());
  vector<int> mod(N+1,0);
  mod[0] = 0;
  map<int,ll> dic;
  ll ten = 1;
  dic[0]++;
  rep(i,N) {
    int now = S[i] - '0';
    mod[i+1] = (ten * now % 2019 + mod[i]) % 2019;
    ten = ten * 10 % 2019;
    dic[mod[i+1]]++;
  }
  ll ans = 0;
  for (auto it = dic.begin() ; it != dic.end() ; it++) {
    //    cout << it->first << " " << it->second << endl; 
    ans = (ans + (it->second) * (it->second - 1) / 2 % MOD) % MOD;
  }
  cout << ans << endl;
}
