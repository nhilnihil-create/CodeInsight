#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int n;

  cin >> n;

  int ans = 0;

  int keta = 0;

  for (int i = 1; i <= n; i++)
  {

    string moji;

    moji = to_string(i);
    if ( moji.length() % 2 == 1)
    {
      ans++;
    }
  }

  cout << ans;
}
