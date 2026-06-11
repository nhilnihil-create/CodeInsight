#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, P, ans = 0;
  string S;
  cin >> N >> P >> S;
  reverse(S.begin(), S.end());
  if (P == 2 || P == 5)
  {
    for (int i = 0; i < N; i++)
    {
      int sint = S[i] - '0';
      if (sint % P == 0)
      {
        ans += N - i;
      }
    }
  }
  else
  {
    vector<int64_t> Count(10000, 0);
    Count[0]++;
    int64_t num = 1, cur = 0;
    for (int i = 1; i <= N; i++)
    {
      int sint = S[i - 1] - '0';
      cur = (cur + sint * num) % P;
      Count[cur]++;
      num *= 10;
      num %= P;
    }
    for (int64_t c : Count)
      ans += c * (c - 1) / 2;
  }
  cout << ans << endl;
}
