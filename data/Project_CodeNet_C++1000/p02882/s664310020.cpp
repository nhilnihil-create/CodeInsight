#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>


using namespace std;
typedef long long ll;

int main(){
  long double a,b,x;
  cin >> a >> b >> x;
  float y = x*1.0/a;
  long double ans = 0;
  if(y<a*b/2.0){
    ans = atan(2.0*x/(a*b*b));
  }else{
    ans = atan(a/(2.0*(-x*1.0/(a*a)+b)));
  }
  ans = 90 - ans/M_PI*180.0;
  printf("%Lf12\n",ans);
}
