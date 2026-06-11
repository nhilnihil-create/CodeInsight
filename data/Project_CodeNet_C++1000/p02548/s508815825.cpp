#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, ct = 0;
  cin >> N;
  for (int a = 1; a < N; a++) {
    ct += (N - 1) / a;
  }
  cout << ct << endl;
}