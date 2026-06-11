#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M, O = 0, P = 0;
  cin >> N >> M;
  for (int i = 1; i < N; i++) {O += i;}
  for (int i = 1; i < M; i++) {P += i;}
  if (N == 1) {O = 0;}
  else if (M == 1) {P = 0;}
  cout << O + P << endl;
}