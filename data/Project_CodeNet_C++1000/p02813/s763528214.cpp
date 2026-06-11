#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> p(n);
  vector<int> q(n);

  for (int i = 0; i < n; i++)
  {
    cin >> p[i];
  }

  for (int i = 0; i < n; i++)
  {
    cin >> q[i];
  }

  vector<int> fac(n);
  for (int i = 0; i < n; i++)
  {
    fac[i] = i + 1;
  }

  int a   = 0;
  int b   = 0;
  int cnt = 0;
  do
  {
    bool yes = true;
    for (int i = 0; i < n; i++)
    {
      if (p[i] != fac[i])
      {
        yes = false;
        break;
      }
    }

    if (yes)
    {
      break;
    }

    cnt++;

  } while (next_permutation(fac.begin(), fac.end()));  // 次の順列を生成
  a = cnt;

  // 再度初期化

  for (int i = 0; i < n; i++)
  {
    fac[i] = i + 1;
  }

  cnt = 0;
  do
  {
    bool yes = true;
    for (int i = 0; i < n; i++)
    {
      if (q[i] != fac[i])
      {
        yes = false;
        break;
      }
    }

    if (yes)
    {
      break;
    }

    cnt++;

  } while (next_permutation(fac.begin(), fac.end()));  // 次の順列を生成

  b = cnt;

  cout << abs(a - b) << endl;

  return 0;
}