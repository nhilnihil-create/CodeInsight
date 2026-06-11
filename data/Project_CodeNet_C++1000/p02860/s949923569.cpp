#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  string S;
  cin >> N >> S;
  bool b = true;
  if (N % 2 == 1) {b = false;}
  for (int i = 0; i < N / 2; i++) {
    if (S.at(i) != S.at(i + N / 2)) {b = false;}
  }
  if (b) {cout << "Yes" << endl;}
  else {cout << "No" << endl;}
}