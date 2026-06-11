#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> s(n, 0);
  for (int i = 0; i < k; i++)
  {
    int d;
    cin >> d;
    for (int i = 0; i < d; i++)
    {
      int a;
      cin >> a;
      s[a - 1]++;
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    if (!s[i])
    {
      ans++;
    }
  }
  cout << ans << endl;
}
