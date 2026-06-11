#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t X, ans = 0;
  cin >> X;
  ans += 1000 * (X / 500);
  ans += 5 * ((X % 500) / 5);
  cout << ans << endl;
}
