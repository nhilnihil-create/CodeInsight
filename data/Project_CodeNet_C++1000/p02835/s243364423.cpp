#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int a[3];
  cin >> a[0] >> a[1] >> a[2];
  if (a[0] + a[1] + a[2] > 21)
  {
    cout << "bust" << endl;
  }
  else
  {
    cout << "win" << endl;
  }

  return 0;
}