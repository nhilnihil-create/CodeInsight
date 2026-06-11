#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  string tmp = S.substr(0, 1);
  int cnt = 1;
  for (int i = 1; i < S.size(); i++) {
    if (tmp == S.substr(i, 1)) {
      if (tmp != S.substr(i, 2)) {
        tmp = S.substr(i, 2);
        cnt++, i++;
      } else {
        break;
      }
    } else {
      tmp = S.substr(i, 1);
      cnt++;
    }
  }

  cout << cnt << "\n";
}