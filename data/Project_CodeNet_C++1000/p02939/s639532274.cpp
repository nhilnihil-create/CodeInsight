#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  string s = "", t = "";
  int ans = 0;
  for (int i = 0; i < S.size(); ++i) {
    s += S[i];
    if (s != t)
      t = s, s = "", ++ans;
  }
  cout << ans << endl;
}