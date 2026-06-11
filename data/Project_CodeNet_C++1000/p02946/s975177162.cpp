#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int k, x;
  cin >> k >> x;

  int minn = max(x - k + 1, -1000000);
  int maxx = min(x + k - 1, 1000000);

  for (int i = minn; i <= maxx; i++)
  {
    if (i == minn)
    {
      cout << i;
      continue;
    }
    cout << " " << i;
  }
  cout << endl;
}
