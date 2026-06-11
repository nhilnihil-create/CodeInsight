#include <bits/stdc++.h>
using namespace std;
int main() 
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  if (N % 2 == 0) {
    int a = A[N / 2 - 1] + A[N / 2];
    int b = B[N / 2 - 1] + B[N / 2];
    cout << b - a + 1 << '\n';
  } else {
    int a = A[N / 2];
    int b = B[N / 2];
    cout << b - a + 1 << '\n';
  }
  return 0;
}