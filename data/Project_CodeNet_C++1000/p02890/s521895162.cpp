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
  int32 n;
  cin >> n;
  map<int32,int32> cnt;
  REP(i,n){
    int32 a;
    cin >> a;
    ++cnt[a];
  }
  vector<int32> cnt2(n+1,0);
  for(auto p : cnt)cnt2[p.second] += p.second;
  vector<int32> cnt3(n+1,0);
  for(auto p : cnt)++cnt3[p.second];
  // REP(i,n+1)ANS(cnt2[i]);
  REP(i,n)cnt2[i+1] += cnt2[i];
  REP(i,n)cnt3[i+1] += cnt3[i];
  vector<int32> f(n+1,0); //f[x] := x個取り出せる長さの最大
  f[0] = INF;
  FOR(i,1,n+1){
    f[i] = (cnt2[i] + i * (cnt.size() - cnt3[i])) / i;
  }
  // REP(i,n+1)cout << i << " " << f[i] << endl;
  FOR(i,1,n+1){
    int32 l=0,r=n+1;
    while(r - l > 1){
      int32 mid = (l + r) / 2;
      if(f[mid] >= i){
        l = mid;
      }else{
        r = mid;
      }
    }
    ANS(l);
  }
  return 0;
}