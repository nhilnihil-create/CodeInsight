#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
int64_t N, K;

bool ok(int64_t m, vector<int64_t> &A, vector<int64_t> &F)
{
  int64_t k = 0;
  for (int i = 0; i < N; i++)
  {
    if (A[i] * F[i] <= m)
      continue;
    k += A[i] - (m / F[i]);
  }
  return k <= K;
}

int main()
{
  cin >> N >> K;
  vector<int64_t> A(N), F(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  for (int i = 0; i < N; i++)
  {
    cin >> F[i];
  }
  sort(A.begin(), A.end());
  sort(F.begin(), F.end());
  reverse(F.begin(), F.end());

  int64_t l = -1, r = (1LL << 62);
  while (r - l > 1)
  {
    int64_t m = (l + r) / 2;
    if (ok(m, A, F))
      r = m;
    else
      l = m;
  }
  cout << r << endl;
}