#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t n, ans = (1LL << 62);
  cin >> n;
  for (int64_t i = 1; i * i <= n; i++)
  {
    if (n % i != 0)
      continue;
    ans = min(ans, i + (n / i) - 2);
  }
  cout << ans << endl;
}
