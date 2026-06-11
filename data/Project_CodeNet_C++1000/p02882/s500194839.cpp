#include <bits/stdc++.h>
using namespace std;

int main(){
  double a,b,x;
  cin >> a >> b >> x;
  
  double ang;
  
  if(x>=a*a*b/2){
    
    ang = atan((b-x/a/a)/(a/2)) * 180/M_PI;
    
  }else{
    
    ang = atan(a*b*b/x/2) * 180/M_PI;
    
  }
  
  printf("%.10lf\n", ang);
  
  return 0;
}


