// warm heart, wagging tail,and a smile just for you!
//
//                            ▒█████▒▒
//                             ██████████▒
//                             ▒████████████▒
//                            ██████████████████
//                           ████████████████████▒
//                          ▒██████████████████████▒
//                          ▒███████████████████████
//                      ▒████▒▒▒▒▒▒█████████████████▒
//                    ███▒▒▒▒▒▒██████████████████████▒▒▒
//                  ▒██▒▒███████████████████████▒▒▒▒▒██████
//                 ▒█████████████████████████▒▒▒▒▒▒█████████▒
//                 ▒█████████████████████▒▒▒▒▒▒██████████████
//                  ▒████         ████▒▒▒▒▒████         ████▒
//              ▒█████▒    ████    ▒▒▒▒███████    ████    ██████▒
//            ▒██▒▒▒▒▒    ██████    █████████    ██████    ██▒▒▒██▒
//           █████████   ████████   █████████   ████████   ▒▒▒▒█████
//          ▒█████████    ██████    ████████▒    ██████    █████████
//          ▒██████████    ████    █████▒▒▒▒▒▒    ████    ██████████
//           ████████████        ▒▒▒▒▒▒▒████████        ███████████▒
//       ▒██████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒███████████████████████████████████▒
//     ███▒▒▒▒▒▒▒▒▒▒▒▒█████████████████████████████████████████▒▒████████▒
//   ▒▒▒▒▒▒▒▒▒██████████████                         ███████▒▒▒▒███████████
//   █████████████████████████                     ███████▒▒▒██████████████▒
//   █████████████████████████████             ███████▒▒▒██████████████████▒
//   ██████████████████████████████████████████████████████████████████████
//    ██████████████████████████████████████████████████████████████████▒
//      ▒█████████████████▒▒▒▒▒▒▒██████████████████████████████████▒▒▒
//
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
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define RFOR(i,a,b) for(int i = (b-1);i>=(a);--i)
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

mat ans(550,vec(550,-1));

void solve(int l, int r, int lev){
  int mid = (l+r)/2;
  //cout << l SP r << endl;
  if(r-l <= 1) return;
  FOR(i,l,mid){
    REP(j,r-mid) ans[i][j+mid] = ans[j+mid][i] = lev;
  }
  solve(l,mid,lev+1);
  solve(mid,r,lev+1);
  return;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  solve(1,n+1,1);

  REP(i,n-1){
    FOR(j,i+1,n) cout << ans[i+1][j+1] << " ";
    cout << endl;
  }

  // REP(i,10){
  // REP(j,10){ cout << ans[i][j] <<" ";} cout << endl;}

  return 0;
}