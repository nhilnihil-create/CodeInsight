#include<bits/stdc++.h>

using namespace std;

int main(){
  long double a,b,x; cin >> a >> b >> x; 
  long double ang;
  if(x > a*a*b/2){
    ang = atan(2*(a*a*b-x)/(a*a*a));
  }else{
    ang = atan((a*b*b)/(2*x)); 
  }
  
  cout << setprecision(12) << ang * 180/3.14159265358979;
  return 0;
  
}