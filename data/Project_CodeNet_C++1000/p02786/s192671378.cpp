#include <bits/stdc++.h>
using namespace std;
int main()
  {long H, c{1}; cin >> H;
  while (H /= 2) c += c + 1;
  cout << c;}