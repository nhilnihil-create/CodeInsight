#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  bool flag = false;
  int ans = 0;

  for (int i = 0; i < S.size(); i++) {
    if (i == S.size() - 2 && S.at(i) == S.at(i + 1)) {
      ans++;
      break;
    }

    if (flag == true && S.at(i) == S.at(i - 1)) {
      ans ++;
      i++;
      flag = false;
    } else {
      ans++;
      flag = true;
    }
  }

  cout << ans << endl;
}