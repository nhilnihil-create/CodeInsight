#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)

int main() {
  int n; cin >> n;
  std::vector<int> p(n);
  std::vector<int> q(n);
  rep(i,n) cin >> p[i];
  rep(i,n) cin >> q[i];

  std::vector<int> v(n);
  rep(i,n) v[i] = i + 1;

  map<std::vector<int>, int> mp;
  do {
    mp[v] = mp.size();
  } while (next_permutation(v.begin(), v.end()));

  int ans = abs(mp[p]-mp[q]);
  cout << ans << endl;
}
