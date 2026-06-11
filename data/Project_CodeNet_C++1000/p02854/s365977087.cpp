#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N;
  cin >> N;

  vector<long long> vec(N), rui(N);
  for (int i = 0; i < N; i++) {
    cin >> vec[i];
    if (i != 0) {
      rui[i] = rui[i - 1] + vec[i];
    } else {
      rui[i] = vec[i];
    }
  }
  long long ans = -1;
  for (int i = 0; i < N - 1; i++) {
    long long l = rui[i];
    long long r = rui[N - 1] - rui[i];
    long long sa = abs(l - r);
    if (ans == -1) {
      ans = sa;
    } else {
      ans = min(ans, sa);
    }
  }

  cout << ans << endl;
}
