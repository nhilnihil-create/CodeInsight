#include <bits/stdc++.h>

using namespace std;

typedef long long llint;

vector<long long> divisors(long long n) {
  vector<long long> res;
  for (long long i = 1; i * i <= n; ++i) {
    if (n % i != 0) continue;
    res.push_back(i);
    if (n / i == i) continue;  // 上の行で追加済み。
    res.push_back(n / i);
  }
  return res;
}

bool func(llint k, llint n) {
  while (n % k == 0) n /= k;
  return (n % k == 1);
}

int main() {
  llint n;
  cin >> n;
  auto v1 = divisors(n);
  auto v2 = divisors(n - 1);
  set<llint> ans;
  for (auto v : v1) {
    if (v == 1) continue;
    if (func(v, n)) ans.insert(v);
  }
  for (auto v : v2) {
    if (v == 1) continue;
    ans.insert(v);
  }
  cout << ans.size() << endl;

  return 0;
}