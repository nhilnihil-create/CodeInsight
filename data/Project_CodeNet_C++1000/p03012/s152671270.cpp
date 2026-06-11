#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  vector<int> w(n);
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> w[i];
    sum += w[i];
  }
  int ans = 100000000;
  int buf = 0;
  for (int i = 0; i < n - 1; i++)
  {
    buf += w[i];
    ans = min(ans, abs((sum - buf) - buf));
  }
  cout << ans << endl;
}
