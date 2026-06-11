#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

#define pi acos(-1)
int main() {
  string s, t;
  cin >> s >> t;
  int i = 0;
  for (; i < s.size() && s[i] == t[i]; i++) ;
  if (i >= s.size()) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}

