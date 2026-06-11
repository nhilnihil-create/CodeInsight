#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, K, s = 0;
  cin >> N >> K;
  vector<int64_t> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
    s += A.at(i);
  }
  vector<int64_t> divisors; // sの約数
  for (int64_t i = 1; i * i <= s; i++)
  {
    if (s % i != 0)
      continue;
    divisors.push_back(i);
    if (s / i != i)
    {
      divisors.push_back(s / i);
    }
  }
  sort(divisors.begin(), divisors.end());
  reverse(divisors.begin(), divisors.end());
  for (auto d : divisors)
  {
    vector<int64_t> rs;
    for (auto a : A)
    {
      if (a % d == 0)
        continue;
      rs.push_back(a % d);
    }
    sort(rs.begin(), rs.end());
    int64_t c1 = 0, c2 = 0;
    int r = rs.size() - 1;
    for (int l = 0; l < rs.size(); l++)
    {
      c1 += rs.at(l);
      while (c1 > c2)
      {
        c2 += d - rs.at(r);
        r--;
      }
      if (l >= r)
        break;
    }
    if (c1 <= K)
    {
      cout << d << endl;
      return 0;
    }
  }
}