#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{

  int h, a;
  cin >> h >> a;

  if(h%a == 0)
    cout << h / a;
  else
  {
    int ans = h / a;
    cout << ans + 1;
  }
}
