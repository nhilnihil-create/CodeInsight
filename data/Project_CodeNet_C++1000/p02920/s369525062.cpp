#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N;
map<ll, ll, greater<ll>> S;
multiset<ll, greater<ll>> Ks;

bool solve() {
  Ks.insert(N);
  for (auto valcnt : S) {
    ll cnt = valcnt.second;
    if (cnt > Ks.size()) return false;
    vector<ll> next;
    for (ll i = 0; i < cnt; ++i) {
      auto it = Ks.begin();
      ll k = *it;
      Ks.erase(it);
      for (ll j = 0; j <= k - 1; ++j) next.push_back(j);
    }
    for (ll j : next) Ks.insert(j);
  }
  return true;
}
int main() {
  cin >> N;
  for (ll i = 0; i < (1 << N); ++i) {
    ll s;
    cin >> s;
    ++S[s];
  }
  cout << (solve() ? "Yes" : "No") << endl;
  return 0;
}
