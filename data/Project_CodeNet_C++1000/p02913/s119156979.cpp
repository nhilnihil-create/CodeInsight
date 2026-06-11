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

vector<int> Z_algo(string S) {
  int N = S.size();
  vector<int> Z(N,0);
  int left = 0;
  for(int i = 1;i<N;i++) {
    int gap = i - left;
    if(i + Z[gap] < left + Z[left]) {
      Z[i] = Z[gap];
    } else {
      int j = max(0,left + Z[left] - i);
      while(i+j < N && S[i+j] == S[j]) j++;

      Z[i] = j;
      left = i;
    }  
  }
  Z[0] = N;
  return Z;
}

int main(){
  int N;cin>>N;
  string S;cin>>S;
  int ans = 0;
  rep(i,N-1) {
    string T = S.substr(i);
    auto Z = Z_algo(T);
    rep(j,T.size()-1) {
      ans = max(ans,min(j+1,Z[j+1]));
    }
  }
  cout<<ans<<endl;
}