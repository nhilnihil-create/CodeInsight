#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int n;
  double d;
  cin >> n >> d;
  int cnt = 0;  
  while(n--){
    double x,y,res;
    cin >> x >> y;
    res = sqrt(x*x + y*y);
    if(res <= d) cnt++;
  }
  cout << cnt;
  return 0;
}
