#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main() {
  int n;
  cin >> n;
  std::vector<int> p(n);
  std::vector<int> q(n);
  rep(i,n) cin >> p.at(i);
  rep(i,n) cin >> q.at(i);
  std::vector<int> a(n);
  rep(i,n) a.at(i) = i+1;
  map<std::vector<int>, int> mp;
  do {
    mp[a] = mp.size();
  } while (next_permutation(a.begin(),a.end()));
  int ans = abs(mp[p] - mp[q]);
  cout << ans << endl;
  return 0;
}
