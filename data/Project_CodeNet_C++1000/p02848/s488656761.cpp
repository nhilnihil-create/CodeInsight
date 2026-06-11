#include <bits/stdc++.h>
using namespace std;
int main()
  {int N; string S; cin >> N >> S;
  for (auto &c : S) c = 'A' + (c - 'A' + N) % 26;
  cout << S;}