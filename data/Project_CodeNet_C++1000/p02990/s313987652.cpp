#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m1(x) memset(x,-1,sizeof(x))
const int INF = 1e9 + 1;
const ll MOD = 1e9 + 7;
const double PI = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461284756482337867831652712019091456485669234603486104543266482133936072602491412737245870066063155881748815209209628292540917153643678925903600113305305488204665213841469519415116094330572703657595919530921861173819326117931051185480744623799;

int main(){
  ll n, k;
  cin >> n >> k;
  ll fact[2000];
  ll inv[2000];
  inv[0] = 1;
  fact[0] = 1;
  for(int i = 1; i <= 2000; i++){
    fact[i] = fact[i-1] * i % MOD;
    ll p = MOD-2, tmp = fact[i];
    inv[i] = 1;
    while(p > 0){
      if(p&1) inv[i] = inv[i] * tmp % MOD;
      tmp = tmp * tmp % MOD;
      p >>= 1;
    }
  }
  inv[0] = 1;
  //出力
  for(int i = 1; i <= k; i++){
    ll ans = fact[k-1]*fact[n-k+1] % MOD;
    ans = ans * inv[k-i] % MOD;
    ans = ans * inv[i-1] % MOD;
    ans = ans * inv[i] %MOD;
    ans = ans * inv[n-k+1-i] % MOD;
    
    ll a = fact[k-1] * inv[i-1] % MOD;
    a = a * inv[k-i] % MOD;
    ll b = fact[n-k+1] * inv[i] %MOD;
    b = b * inv[n-k+1-i] % MOD;
    if(n-k+1-i < 0) ans = 0;
    cout << ans <<endl;
  }
}