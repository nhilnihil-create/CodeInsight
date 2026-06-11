#include<bits/stdc++.h>
using namespace std;
int main(){
  long double a,b,c;
  cin>>a>>b>>c;
  if(a+b+2*sqrt(a*b)<c)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
}