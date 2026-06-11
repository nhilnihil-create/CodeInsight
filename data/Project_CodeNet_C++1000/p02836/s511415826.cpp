#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    int r = N - 1 - i;
    if (S.at(i) != S.at(r)) cnt++;
  }
  cout << cnt / 2 << "\n";
}