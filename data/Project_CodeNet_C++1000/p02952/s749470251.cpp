#include <bits/stdc++.h>
using namespace std;

int func(int N) {
  int res = 0;
  while (N) {
    ++res;
    N /= 10;
  }
  return res;
}

int main() {
  int N; cin >> N;
  int res = 0;
  for (int n = 1; n <= N; ++n) if (func(n) & 1) ++res;
  cout << res << endl;}