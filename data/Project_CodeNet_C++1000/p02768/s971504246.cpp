#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)

#define ALL(v) v.begin(), v.end()


const int MOD = 1000000007;

int64_t modpow(int64_t x, int64_t n) {
    x = x%MOD;
    if(n==0) return 1;  //再帰の終了条件

    else if(n%2==1) {
        return (x*modpow(x, n-1))%MOD;  //nが奇数ならnを1ずらす
    }
    else return modpow((x*x)%MOD, n/2)%MOD;  //nが偶数ならnが半分になる
}

int64_t comb(int64_t n, int64_t k) {
    int64_t x = 1;
    for(int i=n-k+1; i<=n; i++) {
        x = x*i%MOD;
    }

    int64_t y = 1;
    for(int i=1; i<=k; i++) {
        y = y*i%MOD;
    }
    y = modpow(y, MOD-2);

    return x*y%MOD;
}

int main() {
  //std::cout << std::fixed << std::setprecision(20);

  int64_t n, a, b;
  cin >> n >> a >> b;
 

  int64_t ans = 0;
  int64_t all = modpow(2,n) - 1;
  ans = all - comb(n,a) - comb(n,b);
  while(ans < 0) ans += MOD;


  
  cout << ans << endl;

}