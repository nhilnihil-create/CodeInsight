#include <iostream>
#include <string>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int dist(vector<int> a, vector<int> b)
{
  int d = 0;
  rep(i, a.size())
  {
    d += (a[i] - b[i]) * (a[i] - b[i]);
  }

  return d;
}

bool square(int a)
{
  bool result = false;
  for (int i = 0; i * i <= a; i++)
  {
    if (i * i == a)
      result = true;
  }

  return result;
}

int main()
{
  int N, D;
  cin >> N >> D;

  vector<vector<int>> X(N);
  rep(i, N)
  {
    X[i].resize(D);
    rep(j, D)
    {
      cin >> X[i][j];
    }
  }

  int sum = 0;
  rep(i, N)
  {
    for (int j = i + 1; j < N; j++)
    {
      int dist_ = dist(X[i], X[j]);
      if (square(dist_))
        sum++;
    }
  }

  cout << sum << endl;

  return 0;
}
