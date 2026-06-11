#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<pair<ll, ll>> B(n);
  set<pair<int, int>> B_set;
  for (int i = 0; i < n; i++) {
    cin >> B[i].first >> B[i].second;
    B_set.insert(B[i]);
  }

  sort(B.begin(), B.end());

  set<pair<ll, ll>> cost;    // p, q, cost
  int min_cost = n;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      ll p, q;
      p = B[j].first - B[i].first;
      q = B[j].second - B[i].second;
      if (cost.count({p, q})) continue;

      cost.insert({p, q});

      int zero_cost = 0;
      for (int k = 0; k < n; k++) {
        if (B_set.count({B[k].first - p, B[k].second - q})) zero_cost++;
      }

      min_cost = min(n - zero_cost, min_cost);
    }
  }

  cout << min_cost << endl;


  return 0;
}