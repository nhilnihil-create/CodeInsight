#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, ans = 0;
  cin >> N;
  while (cin >> A) ans ^= A;
  cout << ((!ans) ? "Yes" : "No") << "\n";
}