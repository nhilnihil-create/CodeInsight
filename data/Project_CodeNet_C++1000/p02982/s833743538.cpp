#include <bits/stdc++.h>
using namespace std;

int	main()
{
  int		n, d, counter = 0;
  double	sq;
  
  cin >> n >> d;
  vector<vector<int>>	vv(n, vector<int>(d));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < d; j++)
    {
      cin >> vv.at(i).at(j);
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
	  sq = 0;
      for (int k = 0; k < d; k++)
      {
        sq += pow(vv.at(i).at(k) - vv.at(j).at(k), 2);
      }
      if (sq - pow(floor(sqrt(sq)), 2) == 0)
        counter++;
    }
  }
  cout << counter << endl;
  return (0);
}

  