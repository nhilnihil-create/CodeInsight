#include <bits/stdc++.h>
using namespace std;
int64_t MOD = 998244353;

int main()
{
  int64_t N, d, maxd = 0, ans = 1;
  cin >> N;
  vector<int64_t> D(N + 1), Count(N + 1, 0);
  for (int64_t i = 1; i <= N; i++)
  {
    cin >> d;
    D.at(i) = d;
    Count.at(d)++;
    if (d > maxd)
      maxd = d;
  }

  for (int64_t i = 1; i <= N; i++)
  {
    if ((i == 1 && D.at(i) != 0) || (D.at(i) == 0 && i != 1))
    {
      cout << 0 << endl;
      return 0;
    }
  }

  for (int64_t i = 1; i <= maxd; i++)
  {
    if (Count.at(i) == 0)
    {
      cout << 0 << endl;
      return 0;
    }

    int64_t p = 1;
    for (int64_t j = 0; j < Count.at(i); j++)
      p = (p * Count.at(i - 1)) % MOD;
    ans = (ans * p) % MOD;
  }
  cout << (ans % MOD) << endl;
}
