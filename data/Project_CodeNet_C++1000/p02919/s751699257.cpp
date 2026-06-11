#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  int P[N];
  ll where[N];
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    cin >> P[i];
    P[i]--;
    where[P[i]] = i;
  }
  set<int> Set;
  Set.insert(-1);
  Set.insert(N);
  Set.insert(where[N-1]);
  for (ll i = N-2; i >= 0; i--) {
    auto itr3 = Set.lower_bound(where[i]);
    auto itr2 = prev(itr3,1);
    if (*itr3 != N) {
      auto itr4 = next(itr3,1);
      ans += ((ll)*itr4 - (ll)*itr3) * (where[i] - (ll)*itr2) * (i+1);
    }
    if (*itr2 != -1) {
      auto itr1 = prev(itr2,1);
      ans += ((ll)*itr2 - (ll)*itr1) * ((ll)*itr3 - where[i]) * (i+1);
    }
    Set.insert(where[i]);
  }
  cout << ans << endl;
  return 0;
}