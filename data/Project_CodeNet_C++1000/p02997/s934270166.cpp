#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void connect(ll n, vector<pair<ll, ll>> &edges, ll total) {
  ll cnt = 0;
  for (ll i = 1; i < n - 1; i++) {
    for (ll j = i + 1; j < n; j++) {
      if (cnt == total) return;
      edges.push_back(make_pair(i, j));
      cnt++;
    }
  }
}

int main() {
  ll n, k;
  cin >> n >> k;

  ll kmax = (n - 1) * (n - 2) / 2;
  if (k > kmax) {
    cout << -1 << endl;
    return 0;
  }

  vector<pair<ll, ll>> edges;
  for (ll i = 1; i < n; i++) {
    edges.push_back(make_pair(0, i));
  }

  connect(n, edges, kmax - k);

  cout << edges.size() << endl;
  for (auto edge : edges) {
    cout << edge.first + 1 << " " << edge.second + 1 << endl;
  }
}