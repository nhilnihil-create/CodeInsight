#include <bits/stdc++.h>
using namespace std;

int main() {
  int x;
  string s, ans = "";
  cin >> s;
  
  x = s.size();
  
  for (int i = 0; i < x; i++) ans = ans + "x";
  
  cout << ans << endl;;
}