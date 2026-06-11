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

//ex.n = 60 = 2^2 * 3 * 5なら{(2, 2), (3, 1), (5, 1)}を返す
vector<P> prime_factorize(int n){
   vector<P> res;
   for(int p = 2; p * p <= n; p++){
       if(n % p != 0) continue;
       else{
           int num = 0;
           while(n % p == 0) {
               num++;
               n /= p;
           }
           res.push_back(make_pair(p, num));
       }
   }
   if(n != 1) res.push_back(make_pair(n, 1));
   return res;
}

signed main(){
  ios::sync_with_stdio(false);
  cout.tie(0);
  cout.precision(20);

  int n;
  cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vec b(n + 1,0);
  int m = 0;
  RREP(i, n){
    int t = i + 1;
    int cnt = 0;
    //(n / i)回のループ
    while(t < n+1){
      if(b[t] == 1) cnt++; 
      t += i + 1;
    }
    if(cnt % 2 != a[i]){
      b[i + 1]++;
      m++;
    }
  }
  cout << m << endl;
  REP(i, n + 1){
    if(b[i + 1] == 1) cout << i+1 << " ";
  }
  cout << endl;

  return 0;
}