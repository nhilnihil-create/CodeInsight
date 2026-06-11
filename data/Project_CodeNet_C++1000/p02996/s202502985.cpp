#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, t = 0;
  cin >> N;
  vector<pair<int64_t, int64_t>> vp(N);
  for (int i = 0; i < N; i++)
  {
    cin >> vp[i].second >> vp[i].first;
  }
  sort(vp.begin(), vp.end());
  for (int i = 0; i < N; i++)
  {
    t += vp[i].second;
    if (t > vp[i].first)
    {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}