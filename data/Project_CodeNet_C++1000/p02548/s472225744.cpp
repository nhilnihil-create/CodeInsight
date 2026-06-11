#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using ld = long double;
 
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define ALL(x) ((x).begin()), ((x).end())
 
#define READ(x) (cin >> (x))
#define WRITE_N(x) (cout << (x) << endl)
#define WRITE(x) (cout << (x))
#define WRITE_YESNO(x) (WRITE_N((x) ? "Yes" : "No"))
 
#define PRECISE_COUT std::cout << std::setprecision(15) << std::fixed
 
bool xor_logic(bool x, bool y) { return (x && y) || (!x && !y); }
 
#define N_MAX 1000000
#define N_MAX_SQRT 1000
 
ll fact[N_MAX];
 
void init_fact() {
  std::vector<ll> prime_vec;
 
  fact[1 - 1] = 1;
  for (size_t i = 2; i <= N_MAX; i++) {
    bool is_prime = true;
    for (auto &&p : prime_vec) {
      if (i % p == 0) {
        fact[i - 1] = p;
        is_prime = false;
        break;
      }
      if (p * p > i) {
        break;
      }
    }
 
    if (is_prime) {
      fact[i - 1] = i;
      prime_vec.push_back(i);
    }
  }
}
 
unordered_map<ll, ll> factorize(ll n) {
  unordered_map<ll, ll> retv;
  while (n > 1) {
    ll f = fact[n - 1];
    retv[f]++;
    n /= f;
  }
 
  return retv;
}
 
ll count_divider(ll n) {
  unordered_map<ll, ll> factor_dict = factorize(n);
  ll retv = 1;
  for (auto &&p : factor_dict) {
    retv *= p.second + 1;
  }
  return retv;
}
 
ll solve(ll N) {
  init_fact();
  ll ans = 1;
  for (ll i = 2; i < N; i++) {
    ans += count_divider(i);
  }
 
  return ans;
}
 
int main() {
  // get values from input
  cin.tie(0);
  ios::sync_with_stdio(false);
 
  ll N;
  cin >> N;
  // main procedure
  ll ans = solve(N);
 
  // output
  cout << ans << endl;
 
  return 0;
}