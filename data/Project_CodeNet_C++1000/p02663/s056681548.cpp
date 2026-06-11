#include <bits/stdc++.h>

using namespace std;

typedef long long llint;

int main() {
  llint h1, h2, m1, m2, k;
  cin >> h1 >> m1 >> h2 >> m2 >> k;
  int a = (h2 - h1) * 60 + (m2 - m1);
  cout << max(0LL, a - k) << endl;
  return 0;
}