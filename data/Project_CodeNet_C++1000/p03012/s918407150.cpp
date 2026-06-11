#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> a(N);
  for (int i = 0; i < N; ++i) cin >> a[i];
  vector<long long> s(N+1, 0);
  for (int i = 0; i < N; ++i) s[i+1] = s[i] + a[i];
  
  long long res = s[N];
  for (int i = 0; i < N; ++i) {
    res = min(res, abs(s[i] - (s[N] - s[i])));
  }
  cout << res << endl;
}
              