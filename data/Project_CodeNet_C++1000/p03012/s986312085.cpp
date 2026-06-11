#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
  int n;
  int sum = 0, sum2 = 0;
  cin >> n;

  vector<int> w(n);
  rep(i, n)
  {
    cin >> w.at(i);
    sum += w.at(i);
  }

  int ans = 100000000;
  int now = 0;

  for (int i = 0; i < n; i++)
  {
    sum -= w.at(i);
    sum2 += w.at(i);
    int tmp = abs(sum - sum2);
    ans = min(ans, tmp);
  }
  cout << ans;
}
