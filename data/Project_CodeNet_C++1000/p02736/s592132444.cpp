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

int32 mod2comb(int32 n, int32 r){
  return n == (r | (n - r));
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int32 n;
  cin >> n;
  vector<int32> a(n);
  bool oneExit = false;
  REP(i,n){
    char c;
    cin >> c;
    a[i] = c - '1';
    if(a[i] == 1)oneExit = true;
  }
  int32 sum = 0;
  REP(i,n){
    sum += a[i] * mod2comb(n-1, i);
    sum %= 2;
  }
  if(sum == 1){
    ANS(1);
    return 0;
  }
  if(oneExit){
    ANS(0);
    return 0;
  }
  sum = 0;
  REP(i,n){
    sum += a[i] / 2 * mod2comb(n-1, i);
    sum %= 2;
  }
  ANS(sum * 2);
  return 0;
}