#include<bits/stdc++.h>
using namespace std;

int main()
{
  double n,d;
  cin >> n >> d;
  int cnt = 0;
  for(int i = 0; i < n; i++)
  {
    double x,y;
    cin >> x >> y;
    x = abs(x);
    y = abs(y);
    if(sqrt((x*x )+ (y*y)) <= d)
    {
      cnt++;
    }
  }
  cout<<cnt;
 
  return 0;
}
