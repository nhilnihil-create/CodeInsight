#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  map<string, int> s;
  rep(i, n) {
    string st;
    cin >> st;
    s[st]++;
  }
  int maxv = 0;
  for(auto x : s) {
    int v = x.second;
    maxv = max(v, maxv);
  }
  for(auto it = s.begin(); it != s.end(); it++) {
    if(it->second == maxv) {
      cout << it->first << endl;
    }
  }
  return 0;
}