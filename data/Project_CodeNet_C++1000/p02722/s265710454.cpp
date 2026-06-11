#include <bits/stdc++.h>
using namespace std;

vector<int64_t> enumDivisor(int64_t n)
{
  vector<int64_t> res;
  for (int64_t i = 1; i * i <= n; i++)
  {
    if (n % i != 0)
      continue;
    res.push_back(i);
    if (i * i != n)
      res.push_back(n / i);
  }
  return res;
}

int main()
{
  int64_t N;
  cin >> N;
  int64_t ans = 0;
  for (int64_t x : enumDivisor(N))
  {
    if (x == 1)
      continue;
    int64_t tmp = N;
    while (tmp % x == 0)
      tmp /= x;
    tmp %= x;
    if (tmp == 1)
      ans++;
  }
  ans += enumDivisor(N - 1).size() - 1;
  cout << ans << endl;
}
