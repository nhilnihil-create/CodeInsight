#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  int n, k;
  cin >> n >> k;
  int mx = (n - 1) * (n - 2) / 2;
  if (k > mx)
  {
    cout << -1 << endl;
    return 0;
  }
  int m = n - 1 + (mx - k);
  printf("%d\n", m);
  for (int i=1; i<=n; i++)
    for (int j=i+1; j<=n; j++)
    {
      if (m == 0)
        break;
      printf("%d %d\n", i, j);
      m--;
    }
  return 0;
}