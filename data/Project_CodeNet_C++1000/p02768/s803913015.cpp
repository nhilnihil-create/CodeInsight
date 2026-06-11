#include <iostream>

using namespace std;

#define int long long
#define rep(i,n) for(int i=0; i<(int)(n); i++)

const int mod = (int)1e9 + 7;

int pow(int k, int n) {
  if(n <= 0) return 1;
  int m = pow(k, n / 2);
  return (n % 2 ? k : 1) * m % mod * m % mod;
}

int comb(int n, int a) {
  int r = 1;
  rep(i,a) r = r * (n-i) % mod;
  rep(i,a) r = r * pow(i+1, mod-2) % mod;
  return r;
}

signed main() {
  int n, a, b;
  cin >> n >> a >> b;
  cout << (pow(2,n) - 1 + (mod - comb(n,a)) + (mod - comb(n,b))) % mod << endl;
  return 0;
}