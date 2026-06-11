#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
  int n, d, cnt = 0;
  cin >> n >> d;
  vector<vector<int>> v(n);
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<d; j++)
    {
      int k;
      cin >> k;
      v[i].push_back(k);
    }
  }
  for(int i=0; i<n-1; i++)
  {
    for(int j=i+1; j<n; j++)
    {
      long long tmp = 0;
      for(int k=0; k<d; k++)
        tmp += pow(v[i][k] - v[j][k], 2);
      
      int s = (int)sqrt(tmp);
      double t = sqrt(tmp);
      if((double)s == t)
        cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}