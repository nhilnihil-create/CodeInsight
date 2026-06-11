#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long double W,H,X,Y;
  cin>>W>>H>>X>>Y;
  if(X==W/2&&Y==H/2){
    long double S=X*Y*2;
    cout<<fixed<<S<<" "<<1<<endl;
  }
  else{
    long double S=(W/2)*H;
    cout<<fixed<<S<<" "<<0<<endl;
  }
}