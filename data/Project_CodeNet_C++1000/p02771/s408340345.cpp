#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  string ans = "Yes";
  if (a==b && b==c) {
    ans = "No";
  }
  else if (a!=b && b!=c && c!=a) {
    ans = "No";
  }
  cout << ans << endl;
}