#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  long long sum = 0;
  for (int i = 0; i < (int)s.size(); i++) {
    sum += s[i] - '0';
  }
  if (sum % 9 == 0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
