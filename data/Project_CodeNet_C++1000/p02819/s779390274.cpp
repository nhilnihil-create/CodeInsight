#include <bits/stdc++.h>
using namespace std;
bool f(long n)
  {if (n < 2) return false;
  for (long i(2); i * i <= n; ++i) if (!(n % i)) return false;
  return true;}
int main() {int X; for (cin >> X; ; ++X) if (f(X)) cout << X, exit(0);}