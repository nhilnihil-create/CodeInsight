#include <bits/stdc++.h>
using namespace std;
int main()
  {int N; string S, s; cin >> N >> S; s = S.substr(0, N / 2);
  puts(s + s == S ? "Yes" : "No");}