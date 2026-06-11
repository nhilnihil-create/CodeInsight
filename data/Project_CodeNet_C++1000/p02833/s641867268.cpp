#include <bits/stdc++.h>
using namespace std;
int main()
{
  int64_t N, ans = 0;
  cin >> N;
  if (N % 2)
  {
    cout << 0 << endl;
    return 0;
  }
  int64_t n = 5;
  while (n <= N)
  {
    ans += (N / 2) / n;
    n *= 5;
  }
  cout << ans << endl;
}