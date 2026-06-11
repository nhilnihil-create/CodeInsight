#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  for(int i = 0; i < n; i++) cin >> s.at(i);
  map<string, int> v;
  for(string S : s) {
    if(v.count(S)) v.at(S)++;
    else v[S] = 1;
  }
  int m = 0;
  for(auto p : v) {
    auto value = p.second;
    m = max(m, value);
  }
  vector<string> mv(0);
  for(auto p : v) {
    auto key = p.first;
    auto value = p.second;
    if(value == m) mv.push_back(key);
  }
  sort(mv.begin(), mv.end());
  for(auto S : mv) cout << S << endl;
}