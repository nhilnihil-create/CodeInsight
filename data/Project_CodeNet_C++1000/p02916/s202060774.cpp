#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  vector<int> c(n);
  for (int i = 0; i < n; i++)
  {
    int buf;
    cin >> buf;
    a[i] = buf - 1;
  }
  for (int i = 0; i < n; i++)
  {
    cin >> b[i];
  }
  for (int i = 0; i < n - 1; i++)
  {
    cin >> c[i];
  }

  int ans = b[a[0]];
  for (int i = 1; i < n; i++)
  {
    ans += b[a[i]];
    if (a[i] == a[i - 1] + 1)
    {
      ans += c[a[i - 1]];
    }
  }
  cout << ans << endl;
}
