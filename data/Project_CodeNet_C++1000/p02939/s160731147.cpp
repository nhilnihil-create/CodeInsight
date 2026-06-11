#include<bits/stdc++.h>
using namespace std;
int main() {
  string s; cin >> s;
  vector<int> v;
  {
    int l = 1;
    for (int i = 1; i < s.size(); i++) {
      if (s[i] == s[i-1]) l++;
      else {
        v.push_back(l);
        l = 1;
      }
    }
    v.push_back(l);
  }
  int res = 0;
  for (int i = 0; i + 1 < v.size(); i++) {
    if (v[i] % 3 == 0) {
      res += v[i] / 3 * 2;
    } else if (v[i] % 3 == 1) {
      res += v[i] / 3 * 2 + 1;
    } else {
      res += v[i] / 3 * 2 + 2;
      v[i+1]--;
    }
  }
  int x = v.back();
  if (x % 3 == 0) {
    res += x / 3 * 2;
  } else if (x % 3 == 1) {
    res += x / 3 * 2 + 1;
  } else {
    res += x / 3 * 2 + 1;
  }
  cout << res << endl;
}
