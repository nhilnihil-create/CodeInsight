#include <bits/stdc++.h>
#define FOR(i, c) for (int i = 0; i < c; i++)
#define MOD 1000000007
using namespace std;

bool hp(string s, int l, int h) {
  for (; l < h; l++,h--) {
    if (s[l] != s[h]) return false;
  }
  return true;
}
int main() {
  string s;
  cin >> s;
  int n = s.size();
  bool res = hp(s, 0, n-1) && hp(s, 0, (n-1)/2-1) && hp(s, (n+3)/2-1, n-1);
  cout << (res ? "Yes" : "No") << endl;
  return 0;
}


