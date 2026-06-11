#include<bits/stdc++.h>
using namespace std;

int main () {
  string s, ans = "Yes";
  cin >> s;
  
  if (s.size()%2 != 0) {
    ans = "No";
  }
  else {
    for (int i=1; i<s.size(); i+=2) {
      if (s[i-1]!='h' || s[i]!='i') {
        ans = "No";
        break;
      }
    }
  }
  cout << ans << endl;
}