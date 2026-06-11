#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, L;
  cin >> N >> L;
  int ajimin = 1000;
  int imin;
  for (int i = 1; i <= N; i++) {
    if (ajimin > abs(L+i-1)) {
      ajimin = abs(L+i-1);
      imin = i;
    }
  }
  cout << N*(L-1) + N*(N+1)/2 - (L+imin-1) << endl;
}