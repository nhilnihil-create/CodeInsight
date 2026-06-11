#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>

using namespace std;


int main()
{
  int n;
  double m, sum = 0;
  int p[1000] = {0};
  while(true)
  {
    sum = 0;
    cin >> n;
    if(!n)
      break;
    for(int i = 0; i < n; i++)
    {
      cin >> p[i];
      sum += p[i];
    }
    m = sum / n;
    sum	= 0;
    for(int i = 0; i < n; i++)
    {
      sum += pow(p[i] - m, 2);
    }
    printf("%lf\n", sqrt(sum / n));
  }
  return 0;
}