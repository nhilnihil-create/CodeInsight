#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
struct Edge {
  ll to;
  ll cost;
};
 long long modpow(long long a,long long n){
  long long res = 1;
  long long mod = n + 2;
  while(n > 0){
   if(n&1) res = res * a % mod;
   a = a * a % mod;
   n >>= 1;
  }
  return res;
 }
 long long inverse(long long x,long long modding){
  return modpow(x,modding-2);
 }

ll calc(int x,int y){
  //xC(i+j)
  ll bunbo = 1;
  ll bunbotemp = x;
  while(bunbotemp>0){
    bunbo *= bunbotemp;
    bunbotemp--;
    bunbo %= MOD;
  }
  ll bunsi = 1;
  ll bunsitemp=x+y;
  bunbotemp = x;
  while(bunbotemp>0){
    bunsi*= bunsitemp;
    bunsi %= MOD;
    bunsitemp--, bunbotemp--;
  }
  return bunsi * inverse(bunbo, MOD) % MOD;

}
int main() {
  int X, Y;
  cin >> X >> Y;
  if((X+Y)%3!=0){
    puts("0");
    return 0;
  }
  int n = (2 * Y - X) / 3, m = Y - 2 * n;
  if(n<0||m<0){
    puts("0");
    return 0;
  }
  ll ans = calc(n, m);
  if (ans <= 0) ans += MOD;
  cout << ans << endl;
}