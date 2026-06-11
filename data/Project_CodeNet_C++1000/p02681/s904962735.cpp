#include <bits/stdc++.h>
using namespace std;
int main() {
  string S, T;
  cin >> S >> T;
  int s = S.size();
  int t = s + 1;
  string ans = "Yes";
  for (int i = 0; i < s; i++) {
    if (S.at(i) != T.at(i)) {
      ans = "No";
    }
  }
  cout << ans << endl;
}