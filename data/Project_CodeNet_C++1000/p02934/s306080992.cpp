#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  double D = 0.0;
  for (int i = 0; i < N; i++) {
    int O;
    cin >> O;
    D += 1.0 / O;
  }
  cout << 1.0 / D << endl;
}