#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, a, ans = 0, n = 1;
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> a;
    if (a == n)
      n++;
    else
      ans++;
  }
  cout << ((n == 1) ? -1 : ans) << endl;
}