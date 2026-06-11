#include <bits/stdc++.h>
using namespace std;

using int32 = int_fast32_t;
using int64 = int_fast64_t;

const int32 INF = 1e9;
const int32 MOD = 1e9+7;
const int64 LLINF = 1e18;

#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define POSSIBLE cout << ((n) ? "POSSIBLE\n" : "IMPOSSIBLE\n"  )
#define ANS(n) cout << (n) << "\n"
#define REP(i,n) for(int64 i=0;i<(n);++i)
#define FOR(i,a,b) for(int64 i=(a);i<(b);i++)
#define FORR(i,a,b) for(int64 i=(a);i>=(b);i--)
#define ALL(obj) (obj).begin(),(obj).end()
#define pii pair<int32,int32>
#define pll pair<int64,int64>
#define pb(a) push_back(a)

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int32 A,B,m;
  cin >> A >> B >> m;
  vector<int32> a(A),b(B);
  int32 amn=INF,bmn=INF;
  REP(i,A)cin >> a[i], amn=min(amn,a[i]);
  REP(i,B)cin >> b[i], bmn=min(bmn,b[i]);
  int32 ans = amn + bmn;
  REP(i,m){
    int32 x,y,c;
    cin >> x >> y >> c;
    --x;--y;
    ans = min(ans, a[x]+b[y]-c);
  }
  ANS(ans);
  return 0;
}