#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t A, B, N;
  cin >> A >> B >> N;
  if (A >= N) {
    cout << A - N << ' ' << B << endl;
  } else if (B >= N - A) {
    cout << 0 << ' ' << B - N + A << endl;
  } else {
    cout << 0 << ' ' << 0 << endl;
  }
}