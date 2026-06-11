#include <bits/stdc++.h>
using namespace std;
int main()
  {int p, B, s; cin >> p >> p, s = p;
  while (cin >> B) s += min(p, B), p = B;
  cout << s + p;}