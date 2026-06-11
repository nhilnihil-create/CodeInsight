#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main() {
  int d,t,s;
  cin >> d >> t >> s;
  string ans;
  if (t*s >= d) ans = "Yes";
  else ans = "No";
  cout << ans << endl;
}