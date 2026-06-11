#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, p, q;
  cin >> n;
  vector<int> P(n), Q(n), R(n);
  for (int i = 0; i < n; i++)
  {
    cin >> P.at(i);
  }
  for (int i = 0; i < n; i++)
  {
    cin >> Q.at(i);
  }
  for (int i = 1; i <= n; i++)
  {
    R.at(i - 1) = i;
  }
  int cnt = 0;
  do
  {
    if (P == R)
    {
      p = cnt;
    }
    if (Q == R)
    {
      q = cnt;
    }
    cnt++;
  } while (next_permutation(R.begin(), R.end()));
  cout << abs(p - q) << endl;
}