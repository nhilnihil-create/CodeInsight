#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
  int n;
  cin >> n;
  vector<P> ba(n);

  rep(i, n) {
    ll a, b;
    cin >> a >> b;
    ba[i] = P(b, a);
  }
  sort(ba.begin(), ba.end());
  ll now = 0;
  for (auto p : ba) {
    if (now + p.second <= p.first) {
      now += p.second;
    } else {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
