#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const int MAX_N = 2e5 + 10;
int N;
int A[MAX_N], B[MAX_N];

int main()
{
  cin >> N;
  for (int i = 0; i < N; ++i)
  {
    cin >> A[i] >> B[i];
  }
  ll mid_a = 0;
  ll mid_b = 0;
  ll result = 0;
  sort(A, A + N);
  sort(B, B + N);
  if (N % 2 == 0)
  {
    mid_a = (A[N / 2 - 1] + A[N / 2]);
    mid_b = (B[N / 2 - 1] + B[N / 2]);
    result = (mid_b - mid_a) + 1;
  }
  else
  {
    mid_a = A[N / 2];
    mid_b = B[N / 2];
    result = mid_b - mid_a + 1;
  }
  cout << result << endl;
}
