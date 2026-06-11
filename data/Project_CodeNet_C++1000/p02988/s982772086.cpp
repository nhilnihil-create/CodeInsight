#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
const double EPS = 1e-9;
#define INF (1LL<<60)
#define D double
#define fs first
#define sc second
#define int long long
#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define RFOR(i,a,b) for(int i = (int)(b-1);i>=(int)(a);--i)
#define REP(i,n)  FOR(i,0,(n))
#define RREP(i,n) RFOR(i,0,(n))
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x)  cout << #x << " = " << (x) << endl;
#define SP << " " <<
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

signed main(){
  ios::sync_with_stdio(false);
  cout.tie(0);
  cout.precision(20);

  int n;
  cin >> n;
  vector<int> p(n);
  REP(i,n) cin >> p[i];

  int ans = 0;
  FOR(i, 1, n - 1){
    vec t = {p[i-1], p[i], p[i+1]};
    int max = *max_element(t.begin(),t.end());
    int min = *min_element(t.begin(),t.end());
    if(t[1] != max && t[1] != min){
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}