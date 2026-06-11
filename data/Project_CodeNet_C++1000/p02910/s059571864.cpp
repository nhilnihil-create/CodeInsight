#include <bits/stdc++.h>
using namespace std;
int main()
  {string S; cin >> S;
  for (int i{}; i < S.size(); ++i) if ("LR"[i % 2] == S[i]) puts("No"), exit(0);
  puts("Yes");}