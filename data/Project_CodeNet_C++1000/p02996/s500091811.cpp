#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
  int n;
  cin >> n;
  vector<P> v;
  for (int i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    v.push_back(P(b, a));
  }
  sort(v.begin(), v.end());
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    sum += v[i].second;
    if (sum > v[i].first) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
