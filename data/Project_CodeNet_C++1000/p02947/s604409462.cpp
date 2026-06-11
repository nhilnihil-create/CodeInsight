#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N;
  cin >> N;
  vector<string> s(N);
  rep(i,N) cin >> s[i];
  rep(i,N) sort(s[i].begin(), s[i].end());
  map<string, ll> mp;
  rep(i,N) mp[s[i]]++;
  ll ans = 0;
  auto begin = mp.begin(), end = mp.end();
  for (auto i = begin; i != end; i++) ans += (i->second)*(i->second - 1) / 2;
  cout << ans << endl;
  return 0;
}