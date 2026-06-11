#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string s, t;
  cin >> n >> s >> t;
  string res;
  for (int i = 0; i < n; i++) {
    res.push_back(s[i]);
    res.push_back(t[i]);
  }
  cout << res << endl;
}