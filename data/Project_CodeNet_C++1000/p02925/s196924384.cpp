#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, a;
  cin >> N;
  vector<vector<int64_t>> A(N, vector<int64_t>(N - 1));
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N - 1; j++)
    {
      cin >> A.at(i).at(j);
      A.at(i).at(j)--;
    }
    reverse(A.at(i).begin(), A.at(i).end());
  }
  vector<pair<int64_t, int64_t>> Q;
  auto check = [&](int i) {
    if (A.at(i).size() == 0)
      return;
    int j = A.at(i).back();
    if (A.at(j).size() == 0)
      return;
    if (A.at(j).back() == i)
    {
      if (i > j)
        swap(i, j);
      Q.push_back({i, j});
    }
  };
  for (int i = 0; i < N; i++)
  {
    check(i);
  }
  int64_t day = 0;
  while (Q.size())
  {
    day++;
    sort(Q.begin(), Q.end());
    Q.erase(unique(Q.begin(), Q.end()), Q.end());
    vector<pair<int64_t, int64_t>> prevQ;
    swap(Q, prevQ);
    for (auto p : prevQ)
    {
      int64_t i, j;
      tie(i, j) = p;
      A.at(i).pop_back();
      A.at(j).pop_back();
    }
    for (auto p : prevQ)
    {
      int64_t i, j;
      tie(i, j) = p;
      check(i);
      check(j);
    }
  }
  for (int i = 0; i < N; i++)
  {
    if (A.at(i).size())
    {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << day << endl;
}
