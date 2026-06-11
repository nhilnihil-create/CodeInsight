#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;

  cin >> N;

  vector<int> P(N);

  for (int i = 0; i < N; i++)
  {
    cin >> P.at(i);
  }

  int cnt = 0;
  int min_num = INT_MAX;

  for (int i = 0; i < N; i++)
  {
    min_num = min(min_num, P.at(i));
    if (min_num >= P.at(i))
    {
      cnt++;
    }
  }

  cout << cnt << endl;
}
