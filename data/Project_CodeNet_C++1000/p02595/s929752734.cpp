#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int64_t D;
  cin >> N >> D;
  int cnt = 0;
  for (int i; i < N; i++) {
    int64_t X, Y;
    cin >> X >> Y;
    if (X * X + Y * Y <= D * D) cnt++;
  }
  cout << cnt << endl;
}