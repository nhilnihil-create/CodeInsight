#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
  string s;
  cin >> s;
  bool flag = false;
  rep(i,3) {
    if (s[i] == '7') flag = true;
  }
  cout << (flag ? "Yes" : "No") << endl;
  return 0;
}