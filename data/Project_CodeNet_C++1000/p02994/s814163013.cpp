#include <bits/stdc++.h>
using namespace std;

int main() {
 int N, L;
  cin >> N >> L;
  if (L + 1 - 1 > 0) {
    cout << (N - 1) * (L - 1) + ((N - 1) * (N + 2)) / 2 << endl;
  }
  else if (L + N - 1 < 0) {
    cout << (N - 1) * (L - 1) + ((N - 1) * N) / 2 << endl;
  }
  else {
    cout << N * (L - 1) + (N * (1 + N)) / 2 << endl;
  }
}