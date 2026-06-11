#include <bits/stdc++.h>
using namespace std;

using int32 = int_fast32_t;
using int64 = int_fast64_t;

const int32 INF = 1e9;
const int32 MOD = 1e9+7;
const int64 LLINF = 1e18;

#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define ANS(n) cout << (n) << "\n"
#define REP(i,n) for(int64 i=0;i<(n);++i)
#define FOR(i,a,b) for(int64 i=(a);i<(b);i++)
#define FORR(i,a,b) for(int64 i=(a);i>=(b);i--)
#define ALL(obj) (obj).begin(),(obj).end()
#define pii pair<int32,int32>
#define pll pair<int64,int64>
#define pb(a) push_back(a)
#define mp make_pair

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int32 n,k;
  cin >> n >> k;
  // vector<int32> a(n);
  // REP(i,n)cin >> a[i];
  // vector<int32> asum(n+1,0);
  // REP(i,n)asum[i+1] = (asum[i] + a[i] - 1 + k) % k;
  vector<int32> asum(n+1,0);
  REP(i,n){
    int32 a;
    cin >> a;
    asum[i+1] = (asum[i] + a - 1 + k) % k;
  }
  // vector<int32> cnt(k,0);
  map<int32,int32> cnt;
  int64 ans = 0;
  REP(i,n+1){
    ans += cnt[asum[i]];
    cnt[asum[i]]++;
    if(i-k+1 >= 0)
      cnt[asum[i-k+1]]--;
  }
  ANS(ans);
  return 0;
}