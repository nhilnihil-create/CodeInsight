#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    sum += a[i];
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    if (a[i] >= (double)sum / (4 * m))
    {
      ans++;
    }
  }
  if (ans >= m)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}
