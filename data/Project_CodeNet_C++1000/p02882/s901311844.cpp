#include <bits/stdc++.h>
#include<math.h>
using namespace std;
using ll = long long;

int main(){
 int a, b, x;
 double theta;
 const double PI = acos(-1);
 cin >> a>> b >> x;
  if(a*a*b>=2*x){
 theta = atan( a*b*b/(2.0*x)) * 360.0 / (2.0*PI);
  printf("%.10f\n", theta);
  return 0;
 }else{
  theta = atan( (2.0*(a*a*b-x))/(1.0*a*a*a)) * 360.0 / (2.0*PI);
  printf("%.10f\n", theta);
  return 0;
 }
}
 