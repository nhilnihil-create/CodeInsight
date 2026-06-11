/* C - Ubiquity */

#include <bits/stdc++.h>
using namespace std;

static int mod = 1000000007;

int pow_rev(int x, int n){
  if(n == 0) return 1;
  long long a = x;
  for(int i = 1; i < n; i++){
    a *= x;
    a %= mod;
  }
  return a;
}

/*
int pow_rev(int x, int n){
  if(n == 0) return 1;
  else if(n == 1) return x;
  else if(n % 2 == 0) return pow_rev(x * x, n / 2) % mod;
  else return x * pow_rev(x, n - 1) % mod;
}
*/

int main(){
  int N, ans = 0;
  cin >> N;
  ans += pow_rev(10, N);
  ans %= mod;
  ans += pow_rev(8, N);
  ans %= mod;
  ans -= pow_rev(9, N);
  if(ans < 0) ans += mod;
  ans -= pow_rev(9, N);
  if(ans < 0) ans += mod;
  cout << ans << endl;
}
