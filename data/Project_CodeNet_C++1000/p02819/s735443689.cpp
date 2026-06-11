#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef pair<int, int> P;

const long double EPS = 1e-10;
const long long INF = 1e18;
const int MOD = (int)1e9 + 7;
const long double PI = acos(-1.0L);

bool is_prime(long long N) {
  if (N == 1) return false;
  for (long long i = 2; i * i <= N; ++i) {
    if (N % i == 0) return false;
  }
  return true;
}

int main() {
  int x;
  cin >> x;
  while (!is_prime(x)) x++;
  cout << x << endl;

  return 0;
}