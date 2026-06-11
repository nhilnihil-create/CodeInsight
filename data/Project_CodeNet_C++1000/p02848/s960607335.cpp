#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;cin>>n;
  string s;cin>>s;
//  cout << (int)'A' << endl << (int)'Z' << endl;
  for (int i=0; i<s.size();i++){
    if (n + (int)s[i] > 90) cout << (char)(n + (int)s[i] - 26);
    else cout << (char)(n + (int)s[i]);

  }
  cout << endl;

  return 0;
}
