#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N;
  cin >> N;
  long long ans = 0;
  for (long long i = 1; i <= N; i++) {
    long long x = N / i;
    ans += x * (x + 1) / 2 * i;
  }
  cout << ans << endl;
}
