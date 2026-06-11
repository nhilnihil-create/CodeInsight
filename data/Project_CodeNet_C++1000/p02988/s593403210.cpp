#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void solve(ll n, vector<ll> p) {
  int ans{};
  for (auto i=0; i!=n-2; ++i) {
    if ((p[i]<p[i+1]&&p[i+1]<p[i+2])
        || (p[i]>p[i+1]&&p[i+1]>p[i+2])) ++ans;
  }
  cout << ans << endl;
}

int main() {
  ll n;
  cin >> n;
  vector<ll> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  solve(n, move(p));
  return 0;
}
