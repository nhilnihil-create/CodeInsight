#include<bits/stdc++.h>
using namespace std;
main(){
  long long a,b,amari;
  long long x,y;
  cin>>a>>b;
  x=max(a,b);
  y=min(a,b);
  amari=x%y;
  while(amari!=0){
    x=y;
    y=amari;
    amari=x%y;
  }
  cout<<y<<endl;
}