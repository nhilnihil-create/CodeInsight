#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;

int main() {
  string s;
  cin >> s;
  map<char, int> mp;
  bool flg = true;
  for(auto x : s) ++mp[x];
  if(mp.size() == 2) {
    for(auto x : mp) {
      if(x.second != 2) flg = false;
    }
    if(flg) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  
  cout << "No" << endl;
  return 0;
}
