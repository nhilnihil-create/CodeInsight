#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
  string s, t;
  cin >> s >> t;
  vector<vector<ll>> X(26);
  int _S = s.size(), _T = t.size();
  REP(i, _S) { X[s[i] - 'a'].push_back(i); }
  ll roop = 0, now = -1;
  REP(i, _T) {
    auto itr = upper_bound(X[t[i] - 'a'].begin(), X[t[i] - 'a'].end(), now);
    if (itr != X[t[i] - 'a'].end()) {
      now = *itr;
      continue;
    }
    roop++, now = -1;
    itr = upper_bound(X[t[i] - 'a'].begin(), X[t[i] - 'a'].end(), now);
    if (itr != X[t[i] - 'a'].end()) {
      now = *itr;
      continue;
    }
    cout << -1 << endl;
    return 0;
  }
  cout << roop * _S + now + 1 << endl;
}