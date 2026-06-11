#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  vector<int> v(n);
  vector<int> p(n);
  vector<int> q(n);
  for (int i = 0; i < n; i++)
  {
    v[i] = i + 1;
  }
  for (int i = 0; i < n; i++)
  {
    cin >> p[i];
  }
  for (int i = 0; i < n; i++)
  {
    cin >> q[i];
  }
  int a, b;
  int cnt = 1;
  do
  {
    int pe = 0;
    int qe = 0;
    for (int i = 0; i < n; i++)
    {
      if (v[i] == p[i])
      {
        pe++;
      }
      if (v[i] == q[i])
      {
        qe++;
      }
    }

    if (pe == n)
    {
      a = cnt;
    }
    if (qe == n)
    {
      b = cnt;
    }
    cnt++;

  } while (next_permutation(v.begin(), v.end()));
  cout << abs(a - b) << endl;
}
