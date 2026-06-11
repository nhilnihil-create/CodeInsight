#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long long N;
  cin >> N;
  vector<long long> A(N + 1), B(N);
  for(long long i = 0; i < N + 1; ++i) {
    cin >> A[i];
  }
  for(long long i = 0; i < N; ++i) {
    cin >> B[i];
  }

  long long ans = 0;
  for(long long i = 0; i < N; ++i) {
    long long left = min(A[i], B[i]);
    ans += left;
    A[i] -= left;
    B[i] -= left;

    long long right = min(A[i + 1], B[i]);
    ans += right;
    A[i + 1] -= right;
    B[i] -= right;
  }

  cout << ans << endl;

  return 0;
}
