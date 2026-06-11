#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &ai: a) cin >> ai;
  ll sum = 0;
  ll cur_max = 0;
  for (auto ai: a) {
    cur_max = max(cur_max, ai);
    sum += cur_max - ai;
  }
  cout << sum << '\n';
  return 0;
}
