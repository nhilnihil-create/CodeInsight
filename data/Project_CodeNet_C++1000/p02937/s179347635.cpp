#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  string s,t;
  cin >> s >> t;
  vector<ll> A[26];
  for (int i = 0; i < s.size(); i++) {
    A[s[i] - 'a'].push_back(i+1);
  }
  ll ans = 0;
  for (int i = 0; i < t.size(); i++) {
    char c = t[i];
    ll spot = ans % s.size();
    if (A[c - 'a'].size() == 0) {
      cout << -1 << endl;
      return 0;
    }
    auto itr = upper_bound(A[c-'a'].begin(),A[c-'a'].end(),spot);
    if (itr == A[c-'a'].end()) {
      ans += s.size() + A[c-'a'][0] - spot;
    } else {
      ans += *itr - spot;
    }
  }
  cout << ans << endl;
  return 0;
}