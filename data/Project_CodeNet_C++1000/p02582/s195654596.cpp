#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main() {
  string S;
  cin >> S;
  int cnt = 0, ans = 0;

  for (int i = 0; i < S.size(); i++) { 
    if (S[i] == 'R') {
      cnt += 1;
      ans = max(ans, cnt);
    }
    else cnt = 0;
  }

  cout << ans << endl;
}