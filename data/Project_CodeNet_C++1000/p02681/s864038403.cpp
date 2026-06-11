#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string s, t;
  cin >> s >> t;

  string result;
  if (t.substr(0, t.size() - 1) == s) {
    result = "Yes";
  } else {
    result = "No";
  }

  cout << result << endl;
  return 0;
}