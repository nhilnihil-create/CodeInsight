#include<bits/stdc++.h>
using namespace std;
const long double p=3.14159265358979;
int main(){
  long double a,b,x;
  cin>>a>>b>>x;
  if(a*a*b/2<x)
    cout<<fixed<<setprecision(16)<<atan((a*a*b-x)*2/a/a/a)*180/p<<endl;
  else
    cout<<fixed<<setprecision(16)<<90-atan(x*2/a/b/b)*180/p<<endl;
}