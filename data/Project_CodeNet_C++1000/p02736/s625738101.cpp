#include <bits/stdc++.h>
using namespace std;

int n;
string s;
vector<int> v, tmp;

int solve();

int main() {
  cin >> n >> s;
  for(int i = 0; i < n; ++i) v.push_back(s[i] - '0');
  cout << solve() << endl;
  return 0;
}

int solve() {
  bool ch = 0;
  for(int i = 0; i < n; ++i)
    if(--v[i] == 1) ch = 1;
  if(ch) {
    ch = 0;
    for(int i = 0; i < n; ++i)
      if(v[i] == 1) ch ^= ((n - 1) & i) == i;
    return ch;
  }
  ch = 0;
  for(int i = 0; i < n; ++i)
    if(v[i] == 2) ch ^= ((n - 1) & i) == i;
  return ch * 2;
}
