#include<bits/stdc++.h>
using namespace std;
int main(){
  double a,b,x;cin>>a>>b>>x;
  x/=a;
  if((double)a*b/2>=(double)x){
    cout << fixed << setprecision(15)<<atan(b*b/(2*x))*180/(4*atan(1))<<endl;
    return 0;
  }
  else{
    cout << fixed << setprecision(15)<<atan(2*(a*b-x)/(a*a))*180/(4*atan(1))<<endl;
    return 0;
  }
}