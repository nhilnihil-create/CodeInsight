#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N, A, B;
  cin >> N >> A >> B;
  if (A == 0) {
    cout << 0 << endl;
  } else {
    if (N % (A + B) <= A) {
      cout << N/(A+B) * A + N%(A+B) << endl;
    } else {
      cout << N/(A+B) * A + A << endl;
    }
  }
}