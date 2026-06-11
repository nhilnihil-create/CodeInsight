#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    int buf;
    cin >> buf;
    a[i] = buf - 1;
  }
  vector<int> ans(n);
  for (int i = 0; i < n; i++)
  {
    ans[a[i]] = i + 1;
  }
  for (int i = 0; i < n; i++)
  {
    if (i)
    {
      cout << " ";
    }
    cout << ans[i];
  }
  cout << endl;
}
