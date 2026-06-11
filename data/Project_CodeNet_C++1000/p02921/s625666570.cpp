#include <bits/stdc++.h>
using namespace std;

int main () {
  string s,t;
  cin >> s >> t;
  
  int i=0;
  int ans=0;
  for (char x :s) {
    if (x==t[i]) ++ans;
    ++i;
  }
  
  cout << ans << endl;
  
  return 0;
}