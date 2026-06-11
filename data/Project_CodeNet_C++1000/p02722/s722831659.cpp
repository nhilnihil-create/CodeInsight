#include <bits/stdc++.h>
using namespace std;

vector<long> div(long n) {
  vector<long> v;
  for (long i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      v.push_back(i);
      if (i * i != n) v.push_back(n / i);
    }
  }
  sort(begin(v), end(v));
  return v;
}

int main() {
  long N;
  cin >> N;
  set<long> ans;
  for (auto a : div(N)) {
    if (a == 1) continue;
    auto n = N;
    while (n % a == 0) n /= a;
    if (n % a == 1) ans.insert(a);
  }
  for (auto a : div(N - 1)) {
    if (a == 1) continue;
    ans.insert(a);
  }
  cout << ans.size() << "\n";
}