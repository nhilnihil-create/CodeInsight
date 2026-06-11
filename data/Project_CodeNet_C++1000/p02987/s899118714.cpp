#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  bool bl = false;
  if (s[0]==s[1] && s[2]==s[3] && s[0]!=s[2]) bl = true;
  if (bl) puts("Yes");
  else puts("No");
  return 0;
}