#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  int ans = 0;

  for (int i = 1; i <= n; i++)
  {
    string s = to_string(i);
    if (s.length() % 2 != 0)
    {
      ans++;
    }
  }
  cout << ans << endl;
}
