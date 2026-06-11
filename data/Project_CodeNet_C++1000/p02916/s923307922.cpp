#include <iostream>
using namespace std;

int main()
{
  int N, res;
  cin >> N;
  int A[N], B[N], C[N - 1];
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < N; i++) cin >> B[i];
  for (int i = 0; i < N - 1; i++) cin >> C[i];

  res = B[A[0] - 1];
  for (int i = 1; i < N; i++)
  {
    res += B[A[i] - 1];
    if (A[i] == A[i - 1] + 1)
      res += C[A[i] - 2];
  }
  cout << res << endl;
  return 0;
}
