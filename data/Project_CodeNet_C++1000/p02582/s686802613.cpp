#include<bits/stdc++.h>
using namespace std;

int main () {
  string s;
  int a = 0, ans = 0;
  cin >> s;
  
  for (int i = 0; i < 3; i++) {
    if (s[i] == 'R') {
      a ++;
    }
    if (s[i] != 'R' || i == 2) {
      ans = max(a,ans);
      a = 0;
    }
  }
  cout << ans << endl;
}