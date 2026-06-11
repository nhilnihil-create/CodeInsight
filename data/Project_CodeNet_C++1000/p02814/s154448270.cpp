#include <bits/stdc++.h>
using namespace std;

int64_t LCM(int x, int y)
{
  return x / __gcd(x, y) * y;
}

int f(int x)
{
  int ret = 0;
  while (x % 2 == 0)
  {
    x /= 2;
    ret++;
  }
  return ret;
}

int main()
{
  int64_t N, M;
  cin >> N >> M;
  vector<int64_t> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
    A.at(i) /= 2;
  }
  int t = f(A[0]);
  for (int i = 0; i < N; i++)
  {
    if (f(A[i]) != t)
    {
      cout << 0 << endl;
      return 0;
    }
    A[i] >>= t;
  }
  M >>= t;
  int64_t l = 1;
  for (int i = 0; i < N; i++)
  {
    l = LCM(l, A[i]);
    if (l > M)
    {
      cout << 0 << endl;
      return 0;
    }
  }
  int64_t ans = (M / l + 1) / 2;
  cout << ans << endl;
}
