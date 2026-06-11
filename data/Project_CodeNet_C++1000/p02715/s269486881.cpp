#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <iomanip>
#include <cmath>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ll long long
using namespace std;
const int N = 200042;
const int m = 1e9 + 7;
int add(int x, int y) {
  x += y;
  while(x >= m) x -= m;
  while(x < 0) x += m;
  return x;
}
ll mul(ll x, ll y) {
  ll ans = (x * 1ll * y) % m;
  while(ans < 0) ans += m;
  return ans;
}
int binpow(int x, int y) {
  int z = 1;
  while(y) {
    if(y & 1) z = mul(z, x);
    x = mul(x, x);
    y >>= 1;
  }
  return z;
}
int inv(int x) {
  return binpow(x, m - 2);
}
int divide(int x, int y) {
  return mul(x, inv(y));
}
int fact[N];
void precalc() {
  fact[0] = 1;
  for(int i = 1; i < N; i++) fact[i] = mul(fact[i - 1], i);
}
int C(int n, int k) {
  return divide(fact[n], mul(fact[k], fact[n - k]));
}
int A(int n, int m) {
  return divide(fact[n], fact[n - m]);
}
int main() {

  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  precalc();

  int n = 0, k = 0, ans = 0, one = 0;

  cin >> n >> k;

  vector<int> toadd(k + 1);

  for(int i = 1; i <= k; i++) toadd[i] = i;

  for(int i = 1; i <= k; i++) {
    for(int j = 2 * i; j <= k; j += i) toadd[j] -= toadd[i];
  }

  for(int i = 1; i <= k; i++) ans = add(ans, mul(toadd[i], binpow(k / i, n)));

  cout << ans;

  return 0;
}
/*

*/
