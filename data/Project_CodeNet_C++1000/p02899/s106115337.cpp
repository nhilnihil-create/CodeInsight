#include <bits/stdc++.h>
using namespace std;
int main()
  {int N, A; cin >> N;
  int B[N]; for (int i{1}; cin >> A; ++i) B[--A] = i;
  for (int b : B) cout << b << " ";}