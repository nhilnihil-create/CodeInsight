#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <bitset>
#include <complex>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <cassert>
#include <functional>

typedef long long ll;
using namespace std;

#ifndef LOCAL
#define debug(x) ;
#else
#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;

template<typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &p) {
  out << "{" << p.first << ", " << p.second << "}";
  return out;
}

template<typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  out << '{';
  for (const T &item : v) out << item << ", ";
  out << "\b\b}";
  return out;
}
#endif

#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 200010

vector<ll> factmemo, factmemoInv;
ll factmemoMod = -1;

ll factorial(int n, int M) {
  if (factmemoMod == M) return factmemo[n];
  if (n <= 1) return 1;

  ll res = 1;
  for (int i = 1; i <= n; i++) res = res * i % M;
  return res;
}

ll power(ll k, ll n, int M) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * k % M;
    k = k * k % M;
    n /= 2;
  }
  return res;
}

ll C(ll n, ll k, int M) {
  ll a = 1, b = 1;

  for (int i = 0; i < k; i++) {
    a *= n - i;
    b *= i + 1;
    a %= M;
    b %= M;
  }

  return a * power(b, M - 2, M) % mod;
}


int main() {
  int N, A, B;

  cin >> N >> A >> B;

  ll ans = power(2, N, mod) - 1;
  ans += mod - C(N, A, mod);
  ans += mod - C(N, B, mod);

  cout << ans % mod << endl;

  return 0;
}
