#include <bits/stdc++.h>
using namespace std;

int main() {
  string s_arr[] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
  string S; cin >> S;
  int ans = 7;
  for (int i=0; i<7; i++) {
    if (S != s_arr[i]) ans--;
    else break;
  }
  cout << ans << endl;

  return 0;
}
