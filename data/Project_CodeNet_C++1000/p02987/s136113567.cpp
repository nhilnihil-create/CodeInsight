#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string S;
  cin >> S;
  map<char, int> mp;
  rep(i, 4) mp[S[i]]++;
  bool bl = true;
  for (auto p : mp) {
    if (p.second != 2) bl = false;
  }
  puts(bl ? "Yes" : "No");
  return 0;
}