#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, cnt = 0;
  string s;
  cin >> n >> s;
  for (int i = 0; i < n / 2; ++i)
    if (s[i] == s[i + n / 2]) cnt++;
  if (n % 2 == 0)
    cout << ((cnt == n / 2) ? "Yes" : "No") << endl;
  else
    cout << "No" << endl;
}