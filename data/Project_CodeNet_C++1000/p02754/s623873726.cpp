#include <bits/stdc++.h>
using namespace std;

int main() {
  long N, A, B;
  cin >> N >> A >> B;
  long C = A + B;
  long ans = 0;
  ans += A * (N / C);
  ans += min(A, N % C);
  cout << ans << "\n";
}