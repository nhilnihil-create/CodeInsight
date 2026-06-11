#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, X;
  cin >> N;
  if (N%2 == 0) {
    X = N/2;
  }
  else {
    X = N/2 + 1;
  }
  cout << X << endl;
}