#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  
  int step = M / 2;
  for (int i = 0; i < step; i++) {
    cout << i + 1 << " " << M - i << endl;
  }
  step = (M + 1) / 2;
  for (int i = 0; i < step; i++) {
    cout << i + M + 1 << " " << 2 * M + 1 - i << endl;
  }
}