#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++)
  {
    cin >> p[i];
  }
  int ans = 0;
  for (int i = 1; i < n - 1; i++)
  {
    int minn = min(p[i], min(p[i - 1], p[i + 1]));
    int maxx = max(p[i], max(p[i - 1], p[i + 1]));
    if (p[i] != minn && p[i] != maxx)
    {
      ans++;
    }
  }
  cout << ans << endl;
}
