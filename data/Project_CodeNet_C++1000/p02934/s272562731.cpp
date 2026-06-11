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
  
int mgcd(int a, int b){
   int ta = max(a, b);
   int tb = min(a, b);
   int t = INF;
   while(t != 0){
     t = ta % tb;
     ta = tb;
     if(t != 0) tb = t;
   }
   return tb;
}

int mlcm(int a, int b){
  return a * b / mgcd(a, b);
}
  
signed main(){
  ios::sync_with_stdio(false);
  cout.tie(0);
  cout.precision(20);
  
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  
  int b = 1;
  int c = 0;
  int l = a[0];
  FOR(i, 1, n){
    l = mlcm(a[i], l);
  }
  
  b *= l;
  REP(i, n) c += l / a[i];

  cout << (D)b / c << endl;

  return 0;
}