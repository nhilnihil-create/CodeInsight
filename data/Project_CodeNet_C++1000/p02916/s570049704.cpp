#include <bits/stdc++.h>
using namespace std;
int main()
  {int N, s{}, p{-9}; cin >> N;
  int A[N], B[N], C[N - 1]; for (int &a: A) cin >> a, --a; for (int &b: B) cin >> b; for (int &c: C) cin >> c;
  for (int a: A) s += B[a] + (a - p == 1 ? C[p] : 0), p = a;
  cout << s;}