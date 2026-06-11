#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n, x;
  cin >> n >> x;
  int sum = 0;
  int ans = 1;
  for (int i = 0; i < n; i++)
  {
    int l;
    cin >> l;
    sum += l;
    if (sum > x)
    {
      break;
    }
    ans++;
  }
  cout << ans << endl;
}
