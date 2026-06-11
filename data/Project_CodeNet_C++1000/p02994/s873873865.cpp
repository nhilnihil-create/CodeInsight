#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, L, t = 0;
  cin >> N >> L;
  vector<pair<int, int>> v;
  for (int i = 1; i <= N; i++)
  {
    v.push_back({abs(L + i - 1), L + i - 1});
    t += L + i - 1;
  }
  sort(v.begin(), v.end());
  cout << t - v[0].second << endl;
}