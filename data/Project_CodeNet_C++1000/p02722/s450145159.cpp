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

vector<long long> div(long long N) {
  vector<long long> ret = {1};
  for (auto p : primes) {
    if (N % p == 0) {
      int m = ret.size();
      long long ppw = p;
      while (N % p == 0) {
        for (int i = 0; i < m; i++) {
          ret.push_back(ret[i] * ppw);
        }
        N /= p;
        ppw *= p;
      }
    }
  }
  if (N > 1) {
    int m = ret.size();
    for (int i = 0; i < m; i++) {
      ret.push_back(ret[i] * N);
    }
  }
  return ret;
}

bool isok(long long N, long long K) {
  while (N % K == 0) N /= K;
  return N % K == 1;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  long long N;
  cin >> N;
  init(sqrt(N) + 1);
  long long ans = 0;
  auto d = div(N - 1);
  for (long long K : d)
    if (K != 1 && isok(N, K)) ans++;
  d = div(N);
  for (long long K : d)
    if (K != 1 && isok(N, K)) ans++;
  cout << ans << endl;
  return 0;
}
