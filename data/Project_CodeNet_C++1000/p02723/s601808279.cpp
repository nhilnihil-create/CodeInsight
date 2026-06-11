#include <bits/stdc++.h>
#define FOR(i, c) for (int i = 0; i < c; i++)
#define MOD 1000000007
using namespace std;

int main() {
  string s;
  cin >> s;
  bool res = s[0] != s[1] && s[2] == s[3] && s[4] == s[5];
  cout << (res ? "Yes" : "No") << endl;
  return 0;
}

