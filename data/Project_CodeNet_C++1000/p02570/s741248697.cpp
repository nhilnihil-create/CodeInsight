#include <bits/stdc++.h>
using namespace std;

int main() {
  int d, t, s;
  cin >> d >> t >> s;
  d -= t*s;
  if (d <= 0) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}