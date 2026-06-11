#include <bits/stdc++.h>
using namespace std;
//NOT TO SUBMIT IN WRONG PLACE OR BY WRONG COMPILER
//ABC 144, task d, 2020/09/010
//ms,
/*
*/

int main(void){
  int64_t a, b, x;
  double theta1, theta2;
  double deg;
  cin >>a >>b >>x;
  
  theta1 = atan(2.0*b/a - 2.0*x/a/a/a);
  if(b-a*tan(theta1)>=0) deg=theta1*180.0/M_PI;
  else{
    theta2=atan(a*b*b/2.0/x);
    deg=theta2*180.0/M_PI;
  }

  printf("%2.15f", deg);
  return 0;
}
/*
*/
