#include <bits/stdc++.h>
using namespace std;

typedef int_fast32_t int32;
typedef int_fast64_t int64;

const int32 inf = 1e9+7;
const int32 MOD = 1000000007;
const int64 llinf = 1e18;

#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define POSSIBLE(n) cout << ((n) ? "POSSIBLE\n" : "IMPOSSIBLE\n"  )
#define ANS(n) cout << (n) << "\n"
#define REP(i,n) for(int64 i=0;i<(n);++i)
#define FOR(i,a,b) for(int64 i=(a);i<(b);i++)
#define FORR(i,a,b) for(int64 i=(a);i>=(b);i--)
#define all(obj) (obj).begin(),(obj).end()
#define rall(obj) (obj).rbegin(),(obj).rend()
#define fi first
#define se second
#define pb(a) push_back(a)
typedef pair<int32,int32> pii;
typedef pair<int64,int64> pll;

template<class T> inline bool chmax(T& a, T b) {
  if (a < b) { a = b; return true; } return false;
}
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) { a = b; return true; } return false;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int32 n,k;
  cin >> n >> k;
  vector<int32> a(n);
  REP(i,n)cin >> a[i];
  REP(_,k){
    vector<int32> dif(n+2,0);
    REP(i,n){
      dif[max<int32>(0,i-a[i])]++;

      dif[min<int32>(n+1,i+1+a[i])]--;
    }
    int32 cur = 0;
    bool flg = true;
    REP(i,n){
      cur += dif[i];
      a[i] = cur;
      if(a[i] != n)flg = false;
    }
    if(flg)break;
  }
  REP(i,n)cout << a[i] << " ";
  cout << endl;
  return 0;
}