#include <bits/stdc++.h>
using namespace std;
int64_t N, K;

void solve()
{
  cout << (N - 1) + ((N - 1) * (N - 2) / 2) - K << endl;
  for (int i = 2; i <= N; i++)
  {
    cout << 1 << ' ' << i << endl;
  }
  int64_t cnt = (N - 1) * (N - 2) / 2;
  for (int i = 2; i <= N - 1; i++)
  {
    for (int j = i + 1; j <= N; j++)
    {
      if (cnt == K)
        return;
      cout << i << ' ' << j << endl;
      cnt--;
    }
  }
}

int main()
{
  cin >> N >> K;
  int64_t maxk = (N - 1) * (N - 2) / 2;
  if (K <= maxk)
    solve();
  else
    cout << -1 << endl;
}