#include<bits/stdc++.h>
using namespace std;

using LL = long long;

set<LL> prime_factor(LL n) {
  set<LL> prime;
  for(LL i = 2; i <= n / i; ++i)
    for(; n % i == 0; n /= i)
      prime.emplace(i);
  if(n != 1) prime.emplace(n);
  return prime;
}

string solve() {
  LL N;
  cin >> N;
  vector<LL> A(N);
  for(auto& i: A) cin >> i;

  auto pc = [&]() {
    set<LL> used;
    for(auto i: A) for(auto p: prime_factor(i)) {
      if(used.count(p)) return false;
      used.emplace(p);
    }
    return true;
  };

  auto sc = [&]() {
    return 1 == accumulate(begin(A), end(A), A[0], [](auto s, auto i) {return gcd(s, i);});
  };

  if(pc()) return "pairwise coprime";
  if(sc()) return "setwise coprime";
  return "not coprime";
}

int main() {
  cout << solve() << endl;
}
