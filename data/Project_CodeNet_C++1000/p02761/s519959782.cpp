#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> s(m);
  vector<int> c(m);
  for (int i = 0; i < m; i++)
  {
    cin >> s[i] >> c[i];
    s[i]--;
  }
  for (int i = 0; i < pow(10, n); i++)
  {
    string num = to_string(i);
    if (num.length() == n)
    {
      int ok = 1;
      for (int j = 0; j < m; j++)
      {
        if (num[s[j]] - '0' != c[j])
        {
          ok = 0;
        }
      }
      if (ok)
      {
        cout << i << endl;
        return 0;
      }
    }
  }

  cout << -1 << endl;
}
