#include<bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (int)n; i++)

int main(){
  map<string, int> s;
  int n;
  cin >> n;
  rep(i,n) {
    string key;
    cin >> key;
    s[key] += 1;
  }
  int maxv = 0;
  for (const auto &x : s) {
    int v = x.second;
    maxv = max(maxv, v);
  }
  for (auto it = s.begin(); it != s.end(); it++) {
    if (it->second == maxv) {
      cout << it->first << endl;
    }
  }
}
