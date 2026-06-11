#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N;
  cin >> N;

  vector<long long> a(N);
  for (int i = 0; i < N; i++) cin >> a.at(i);

  vector<long long> s(N + 1, 0);
  for (int i = 0; i < N; ++i) s.at(i + 1) = s.at(i) + a.at(i);

  long long ans = 1001001001001;
  for (int i = 0; i < N; i++) {
    ans = min(ans, abs(s.at(i) * 2 - s.at(N)));
  }

  cout << ans << endl;
}
