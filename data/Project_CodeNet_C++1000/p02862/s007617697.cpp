#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int MOD = 1e9+7;
const int N = 1e6+7;

vector<int> mf(N, -1);

int modfact(int n) {
  if (mf[n] != -1) return mf[n];
  if (n == 0) return mf[0] = 1;
  return mf[n] = (ll)n * modfact(n-1) % MOD; 
}

int modinv(int a) {
  int b = MOD, u = 1, v = 0;
  while (b) {
    int t = a / b;
    a -= t * b; swap(a, b);
    u -= t * v; swap(u, v);
  }
  u %= MOD;
  if (u < 0) u += MOD;
  return u;
}

vector<int> mif(N, -1);

int modinvfact(int n) {
  if (mif[n] != -1) return mif[n];
  if (n == 0) return mif[0] = 1;
  return mif[n] = (ll)modinv(n) * modinvfact(n-1) % MOD;
}

int modcomb(int n, int k) {
  return (ll)modfact(n) * modinvfact(k) % MOD * modinvfact(n-k) % MOD;
}

int main() {
  int x, y;
  cin >> x >> y;
  if ((2*x-y)%3 || (2*y-x)%3) {
    cout << 0 << endl;
    return 0;
  }
  int a = (2*x-y)/3;
  int b = (2*y-x)/3;
  if (a < 0 || b < 0) {
    cout << 0 << endl;
    return 0;
  }
  int ans = modcomb(a+b, a);
  if (ans < 0) ans += MOD;
  cout << ans << endl;
  return 0;
}