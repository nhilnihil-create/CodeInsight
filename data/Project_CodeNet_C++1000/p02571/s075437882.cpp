#include<bits/stdc++.h>
using namespace std; 

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); 
  string s, t;
  cin >> s >> t;
  int mx = 0;
  for (int i = 0 ; i <= s.size() - t.size(); i++) {
    int c = 0;
    for (int j = 0 ; j < t.size(); j++) {
      c += s[i + j] == t[ j];
    }
    mx = max(mx, c);
  }
  cout << t.size() - mx << "\n";
}