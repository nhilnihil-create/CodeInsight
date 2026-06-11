#include <bits/stdc++.h>
using namespace std;
int main()
  {int N, X, L, D{}, c{1}; cin >> N >> X;
  while (cin >> L) D += L, c += D <= X;
  cout << c;}