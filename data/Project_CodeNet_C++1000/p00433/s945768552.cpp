#include<iostream>
#include<cmath>
using namespace std;
int main(){
  int s,t,a,b,c,d,max_;
  cin >>a>>b>>c>>d;
  s=a+b+c+d;
  cin >>a>>b>>c>>d;
  t=a+b+c+d;
  max_=max(s,t);
  cout<<max_<<endl;
  return 0;
}