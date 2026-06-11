#include <bits/stdc++.h>
using namespace std;
int main()
  {int N; cin >> N;
  vector<int> A(N), B; for (int &a: A) cin >> a; B = A, sort(rbegin(B), rend(B));
  for (int a : A) cout << B[a == B[0]] << "\n";}