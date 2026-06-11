#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main() {
  string s;
  cin >> s;
  bool ans = true;
  if (s[2] != s[3]) ans = false;
  if (s[4] != s[5]) ans = false;
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}