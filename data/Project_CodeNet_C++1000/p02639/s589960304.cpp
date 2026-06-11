#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
int main()
{
  int x;
  rep(i, 5)
  {
    cin >> x;
    if (!x)
    {
      cout << i + 1;
      return 0;
    }
  }
}
