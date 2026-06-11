#include<bits/stdc++.h>
using namespace std;

int main(){
  long double a,b,c;
  cin>>a>>b>>c;
  //cout<<pow(pow(x2-x1,2)+pow(y2-y1,2),0.5)<<endl;
  cout<<std::fixed<<std::setprecision(10)<<0.5*a*b*sin(c*(M_PI/180))<<endl<<a+b+pow(a*a+b*b-2*a*b*cos(c*(M_PI/180)),0.5)<<endl<<a*b*sin(c*(M_PI/180))/a<<endl;
  //cout<<hypot(x2-x1,y2-y1)<<endl;
}


