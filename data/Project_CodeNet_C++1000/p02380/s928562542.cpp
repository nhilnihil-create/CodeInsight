#include<bits/stdc++.h>
using namespace std;

int main(){
  double a,b,c;
  double ans1,ans2,ans3;
  double rad = M_PI/180;

  cin >> a >> b >> c;
  c *= rad;

  ans1 = (a*b*sin(c))/2;
  printf("%.8f\n",ans1);

  ans2 = a*a + b*b -2*a*b*cos(c);
  ans2 = sqrt(ans2)+a+b;
  printf("%.8f\n",ans2);

  ans3 = ans1/a*2;
  printf("%.8f\n",ans3);

  return (0);
}