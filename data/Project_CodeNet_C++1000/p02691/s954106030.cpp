#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<long long> A(N);
  map<long long, long long> sum;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    sum[i + A[i]]++;
  }

  long long ans = 0;
  for (int i = 0; i < N; i++) {
    long long z = i - A[i];
    if (sum.count(z)) {
      ans += sum[z];
    }
  }
  cout << ans << endl;
  return 0;
}