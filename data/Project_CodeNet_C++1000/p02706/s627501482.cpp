#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M;
  cin >> N >> M;
  int O = 0;
  for (int i = 0; i < M; i++) {
    int P;
    cin >> P;
    O += P;
  }
  if (N < O) {cout << -1 << endl;}
  else {cout << N - O << endl;}
}