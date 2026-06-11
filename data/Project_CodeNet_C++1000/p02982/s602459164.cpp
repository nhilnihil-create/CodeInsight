#include <iostream>
#include <vector>
using namespace std;

bool isSquare(int num)
{
  int r = (int)floor(sqrt((double)num));
  return (r * r) == num;
}

int main()
{
  int N, D;
  cin >> N >> D;
  vector<vector<int> > points;
  for (int i = 0; i < N; i++)
  {
    vector<int> point;
    for (int j = 0; j < D; j++)
    {
      int tmp;
      cin >> tmp;
      point.push_back(tmp);
    }
    points.push_back(point);
  }

  int ans = 0;
  for (int i = 0; i < N; i++)
  {
    for (int j = i+1; j < N; j++)
    {
      int sum = 0;
      for (int k = 0; k < D; k++)
      {
        sum += (points[i][k] - points[j][k]) * (points[i][k] - points[j][k]);
      }

      if (isSquare(sum)){
        ans++;
      }
    }
  }

  cout << ans << endl;

  return 0;
}