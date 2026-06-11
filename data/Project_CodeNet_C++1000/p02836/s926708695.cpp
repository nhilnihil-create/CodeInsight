#include <bits/stdc++.h>
using namespace std;
int main()
  {string S; cin >> S;
  int n(S.size()), c{}; for (int i{}; i < n / 2; ++i) c += S[i] != S[n - 1 - i];
  cout << c;}