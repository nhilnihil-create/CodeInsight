#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int n;

  long long money = 1000;

  cin >> n;

  vector<int> a(n);

  rep(i, n)
  {
    cin >> a.at(i);
  }

  rep(i, n - 1)
  {

    if (a.at(i) < a.at(i + 1))
    {
      long long x = money / a.at(i);
      money -= (x * a.at(i));
      money += (x * a.at(i + 1));
    }
  }

  cout << money;
}
