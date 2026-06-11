#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int n;

  cin >> n;

  vector<int> p(n);

  int ans = 0;

  rep(i, n)
  {
    cin >> p.at(i);
  }

  for (int i = 1; i < n - 1; i++)
  {
    if ((p.at(i - 1) > p.at(i) && p.at(i) > p.at(i + 1)) || (p.at(i - 1) < p.at(i) && p.at(i) < p.at(i + 1)))
    {
      ans++;
    }
  }

  cout << ans;
}
