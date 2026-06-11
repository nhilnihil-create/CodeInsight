#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int MOD =  1000000007;
const int INF = 1e11;
using Graph = vector<vector<int>>;

long long modpow(long long a, long long n, long long mod) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % MOD;
    a = a * a % MOD;
    n >>= 1;
  }
  return res;
}

signed main(){
  int N, K;
  cin >> N >> K;

  int ans = 0;
  vector<int> cnt(K+1); //cnt[i]:iがgcdであるような配列の個数
  for( int i = K; i >= 1; i-- ){
    cnt[i] = modpow(K/i, N, MOD);
    for( int j = 2; i*j <= K; j++ ) cnt[i] -= cnt[i*j];
    while( cnt[i] < 0 ) cnt[i] += MOD;
    ans += cnt[i]*i;
    ans %= MOD;
  }
  cout << ans << endl;

}
