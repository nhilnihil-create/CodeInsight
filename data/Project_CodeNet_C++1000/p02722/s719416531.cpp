#include <cmath>
#include <deque>
#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

deque<ll> enumerate_divisors(ll n) {
  deque<ll> ret;
  ll i = floor(sqrt(n));
  if (i*i == n) {
    ret.push_back(i);
    --i;
  }
  while (i) {
    if (n % i == 0) {
      ret.push_front(i);
      ret.push_back(n / i);
    }
    i--;
  }

  return ret;
}

void solve(ll N) {
  auto cnt = enumerate_divisors(N - 1).size() - 1;  // remove 1
  
  auto deq = enumerate_divisors(N);
  
  deq.pop_front();  // remove 1
  for (auto i : deq) {
    auto n = N;
    while (n % i == 0) {
      n /= i;
    }
    if (n % i == 1) {
      ++cnt;
    }
  }
  cout << cnt << endl;
}

int main() {
  ll N;
  cin >> N;
  solve(N);
  return 0;
}
