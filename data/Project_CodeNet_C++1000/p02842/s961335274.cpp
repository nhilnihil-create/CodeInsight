#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  int c1 = floor(N / 1.08);
  int c2 = c1 + 1;

  if (floor(c1 * 1.08) == N) {
    cout << c1 << endl;
    return 0;
  }
  if (floor(c2 * 1.08) == N) {
    cout << c2 << endl;
    return 0;
  }
  cout << ":(" << endl;
}