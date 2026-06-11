#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  map<int, int> mp;
  rep(i, N) {
    cin >> A[i];
    mp[A[i]]++;
  }
  ll total = 0;
  for (auto p : mp) {
    ll x = p.second;
    total += x * (x-1) / 2;
  }
  rep(i, N) {
    ll y = mp[A[i]];
    ll ans = total - 2 * (y-1) / 2;
    cout << ans << '\n';
  }
  return 0;
}