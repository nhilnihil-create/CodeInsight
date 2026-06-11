#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n, k;
  cin >> n >> k;
  
  vector<int> a(n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
    sum += a.at(i);
  }
  
  vector<int> x;
  for (int i = 1; i * i <= sum; i++) {
    if (sum % i == 0) {
      x.emplace_back(i);
      if (sum / i != i) x.emplace_back(sum / i);
    }
  }
  sort(x.rbegin(), x.rend());
  
  for (int i = 0; i < x.size(); i++) {
    vector<int> y(n);
    for (int j = 0; j < n; j++) y.at(j) = a.at(j) % x.at(i);
    sort(y.begin(), y.end());
    int count = 0, keep = 0, now = 0;
    while (y.back() != 0) {
      count += y.at(now);
      keep = y.at(now);
      y.at(now) = 0;
      now++;
      while (keep > 0) {
        if (x.at(i) - y.back() <= keep) {
          keep -= x.at(i) - y.back();
          y.pop_back();
        }
        else {
          y.back() += keep;
          keep = 0;
        }
      }
    }
    if (count <= k) {
      cout << x.at(i) << '\n';
      return 0;
    }
  }
  
  cout << 1 << '\n';
}