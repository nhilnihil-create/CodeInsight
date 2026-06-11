#include <iostream>
using namespace std;

int main()
{
  int N;
  cin >> N;
  long A[N + 1], B[N];
  for (int i = 0; i < N + 1; i++) cin >> A[i];
  for (int i = 0; i < N; i++) cin >> B[i];

  long res = 0;
  for (int i = 0; i < N; i++)
  {
    if (A[i] >= B[i])
    {
      res += B[i];
      continue;
    }
    else
    {
      res += A[i];
      B[i] -= A[i];
    }
    if (A[i + 1] >= B[i])
    {
      res += B[i];
      A[i + 1] -= B[i];
    }
    else
    {
      res += A[i + 1];
      A[i + 1] = 0;
    }
  }
  cout << res << endl;
  return 0;
}
