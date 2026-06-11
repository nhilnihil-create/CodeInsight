#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

map<ll, int> prime_factor(ll n) {
  map<ll, int> res;
  for (ll i = 2; i * i <= n; i++) {
    if (n % i) continue;
    res[i] = 0;
    while (n % i == 0) {
      res[i]++;
      n /= i;
    }
  }
  if (n != 1) res[n] = 1;
  return res;
}

int main() {
  ll A, B;
  cin >> A >> B;
  ll max_v = gcd(A, B);
  auto primes = prime_factor(max_v);
  cout << primes.size() + 1 << endl;
  return 0;
}