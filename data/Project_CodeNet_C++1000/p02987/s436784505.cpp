#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s;cin>>s;
  char st;
  int cnt;
  for (int i=0; i<4;i++) {
    cnt =0;
    st = s[i];
    for (int j=0;j<4;j++){
      if (st == s[j]) cnt++;
    }
    if (cnt != 2) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
