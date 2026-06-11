#include <bits/stdc++.h>
using namespace std;
int main()
  {char a, b; cin >> a >> b;
  cout << min(string(b - '0', a), string(a - '0', b)) << endl;}