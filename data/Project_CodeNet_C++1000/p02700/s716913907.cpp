#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  int ta,ao;
  
  if((c % b) == 0){
    ta = (c / b);
   }else{
    ta = (c / b) + 1;
   }
  
   if((a % d) == 0){
    ao = (a / d);
   }else{
    ao = (a / d) + 1;
   }
  
  if(ta <= ao) {
     cout << "Yes" << endl;
  }else{
     cout << "No" << endl; 
  }
 
}