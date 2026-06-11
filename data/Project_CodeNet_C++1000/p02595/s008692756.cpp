#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N, D, sum = 0;
  cin >> N >> D;
  for (int i = 0; i < N; i++ ) {
    int64_t a, b, d2;
    cin >> a >> b;
    d2 = a*a + b*b;
    if (d2 <= D*D) {
      sum++;
    }
  }
  cout << sum << endl;
}