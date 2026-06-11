#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  map<int, int> mp;
  rep(i, n) ++mp[a[i]];
  int cnt = 0;
  bool exist = false;
  for (auto itr = mp.begin(); itr != mp.end(); ++itr) ++cnt;
  if (cnt == 1 && mp[0] > 0) exist = true;
  if (cnt == 2 && 3 * mp[0] == n) exist = true;
  if (cnt == 3) {
    auto itr = mp.begin();
    int a1 = itr->first;
    int n1 = (itr++)->second;
    int a2 = itr->first;
    int n2 = (itr++)->second;
    int a3 = itr->first;
    int n3 = (itr++)->second;
    if ((a1 ^ a2) == a3 && n1 == n2 && n1 == n3) exist = true;
  }
  
  if (exist) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}