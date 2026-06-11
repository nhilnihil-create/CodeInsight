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

signed main() {
  ios::sync_with_stdio(false);
  cout.tie(0);
  cout.precision(20);

  int n;
  cin >> n;
  vector<P> p(n);
  REP(i,n){
    cin >> p[i].first >> p[i].second;
  }

  sort(p.begin(),p.end(),[](P a, P b){
    return a.second < b.second;
  });

  int time = 0;
  REP(i, n){
    if(time + p[i].first > p[i].second){
      cout << "No" << endl;
      return 0;
    }
    time += p[i].first;
  }

  cout << "Yes" << endl;

  return 0;
}