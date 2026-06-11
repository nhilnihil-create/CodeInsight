#include <bits/stdc++.h>
#include <cstdlib>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;
const int MOD = 1000000007;

long long mod(long long val, long long m) {
  long long res = val % m;
  if (res < 0) res += m;
  return res;
}

bool is_prime(long long N) {
    if (N == 1) return false;
    for (long long i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}

vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0;
        while (N % a == 0) {
            ++ex;
            N /= a;
        }
        res.push_back({a, ex});
    }
    if (N != 1) res.push_back({N, 1});
    return res;
}

int main() {
  ll N,ans=0;
  cin >> N;
  
  for(int i=1;i<N;i++){
  const auto &pf = prime_factorize(i);
    long long res = 1;
    for (auto p : pf) res *= p.second + 1;
    ans += res;
  }
  cout << ans << endl;
  
  return 0;
}
