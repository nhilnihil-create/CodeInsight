#include <bits/stdc++.h>
using namespace std;
int main() {
  int H, N, O = 0;
  cin >> H >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {cin >> A.at(i);}
  for (int i = 0; i < N; i++) {O += A.at(i);}
  if (O >= H) {cout << "Yes" << endl;}
  else {cout << "No" << endl;}
}