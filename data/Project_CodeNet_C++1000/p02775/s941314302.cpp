#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S;
  cin >> S;
  int64_t N = S.size();
  vector<int> v(N);
  for (int i = 0; i < N; i++)
  {
    v[i] = S[i] - '0';
  }
  reverse(v.begin(), v.end());
  v.push_back(0);
  int64_t ans = 0;
  for (int i = 0; i < N; i++)
  {
    if (v[i] <= 4)
    {
      ans += v[i];
    }
    else if (v[i] == 5)
    {
      if (v[i + 1] <= 4)
      {
        ans += v[i];
      }
      else
      {
        ans += (10 - v[i]);
        v[i + 1]++;
      }
    }
    else
    {
      ans += (10 - v[i]);
      v[i + 1]++;
    }
  }
  ans += v[N];
  cout << ans << endl;
}
