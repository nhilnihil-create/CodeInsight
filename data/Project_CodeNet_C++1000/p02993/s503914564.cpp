#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;


int main () {
  string S, ans = "Good";
  cin >> S;
  for(int i = 0; i < 3; i++) {
    if (S.at(i) == S.at(i + 1)) {
      ans = "Bad";
      break;
    }
  }
  cout << ans << endl;
}
