#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[4];
  string ans = "Good";
  for(int i=0;i<4;++i) cin >> s[i];
  for(int i=0;i<3;++i) {
    if(s[i]==s[i+1]) ans = "Bad";
  }
  cout << ans << endl;
}