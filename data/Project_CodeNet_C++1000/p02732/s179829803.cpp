#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  int N;
  cin >> N;
  vector<int> A(N);
  map<int, int> mp;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    mp[A[i]]++;
  }

  int all = 0;
  for (int i = 1; i <= N; i++) {
    all += mp[i] * (mp[i] - 1) / 2;
  }

  for (int i = 0; i < N; i++) {
    cout << all - mp[A[i]] * (mp[A[i]] - 1) / 2 +
                (mp[A[i]] - 1) * (mp[A[i]] - 2) / 2
         << endl;
  }

  return 0;
}