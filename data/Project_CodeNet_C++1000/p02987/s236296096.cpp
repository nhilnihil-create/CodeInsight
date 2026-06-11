#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;


int main () {
  string S, ans = "Yes";
  int all_count = 0;
  cin >> S;

  for (int i = 0; i < 3; i++) {
    int count = 0;
    for (int j = i + 1; j < 4; j++) {
      if (S.at(i) == S.at(j)) count++;
    }
    if (count == 1) all_count++;
  }
  if (all_count != 2) ans = "No";
  cout << ans << endl;
}
