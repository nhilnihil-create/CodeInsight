#include<bits/stdc++.h>
using namespace std ; 
const double PI=  acos(-1.0);

int main(){
   double A , B , H , M ; 
  
   double rad ; 
  
  cin >> A >> B >> H >> M ; 
  
  rad = 2*PI*( (  60*H + M )/720 - M/60.0);

  
   double rsq = (A * A + B * B) - (2.0 * A * B) * cos(rad);
  
  cout << setprecision(14) << sqrt(rsq) << endl ;
}