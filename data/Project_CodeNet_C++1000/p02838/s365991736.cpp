#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;
int main() {
  int n;
  cin >> n;
  vector a(n,0LL);
  for (int i=0; i<n; i++) cin >> a[i];
  
  vector bits(2, vector(60,0LL));
  for (int i=0; i<n; i++) {
    for (int j=0; j<60; j++) {
      bits[(a[i]>>j)&1][j]++;
      bits[(a[i]>>j)&1][j] %= MOD;
    }
  }
  
  long long ans = 0;
  long long d =  1;
  for (int i=0; i<60; i++) {
    ans += (((bits[0][i] * bits[1][i]) % MOD) * d) % MOD;
    d *= 2;
    d %= MOD;
    ans %= MOD;
  }
  
  cout << ans << endl;
}