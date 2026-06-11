#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<long long> A(N), B(N);
  for (int i = 0; i < N; i++)
    cin >> A[i] >> B[i];
  // sort
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  if (N % 2)
  {
    long long mi = A[N / 2], ma = B[N / 2];
    cout << ma - mi + 1 << endl;
  }
  else
  {
    long long mi = A[N / 2 - 1] + A[N / 2];
    long long ma = B[N / 2 - 1] + B[N / 2];
    cout << ma - mi + 1 << endl;
  }
}
