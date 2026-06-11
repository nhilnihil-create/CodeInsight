#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  char ss[n], tt[n];
  for(int i=0; i<n; i++) {
    cout << s.at(i) << t.at(i);
  }
  cout << endl;
}