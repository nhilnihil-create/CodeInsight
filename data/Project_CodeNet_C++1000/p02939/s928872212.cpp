#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string S;
  cin >> S;
  string last = "";
  string tmp = "";
  int ans = 0;
  for (int i = 0; i < S.length(); i++) {
    tmp += S[i];
    if (tmp == last) continue;
    last = tmp;
    tmp = "";
    ans++;
  }
  cout << ans << endl;
  return 0;
}