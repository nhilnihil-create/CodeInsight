#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
#ifdef __LOCAL
#define debug(x) cerr << __LINE__ << ": " << #x << " = " << x << endl
#define debugArray(x, n)                           \
  cerr << __LINE__ << ": " << #x << " = {";        \
  for (long long hoge = 0; (hoge) < (n); ++(hoge)) \
    cerr << ((hoge) ? "," : "") << x[hoge];        \
  cerr << "}" << endl
#else
#define debug(x) (void(0))
#define debugArray(x, n) (void(0))
#endif

vector<int> primes;
void init(int n) {
  primes.push_back(2);
  bool is_prime[n + 1];
  fill(is_prime, is_prime + n + 1, true);
  for (long long p = 3; p <= n; p += 2)
    if (is_prime[p]) {
      primes.push_back(p);
      for (long long i = p * p; i <= n; i += p) is_prime[i] = false;
    }
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  init(1e6);
  int X;
  cin >> X;
  cout << *lower_bound(primes.begin(), primes.end(), X) << '\n';
  return 0;
}
