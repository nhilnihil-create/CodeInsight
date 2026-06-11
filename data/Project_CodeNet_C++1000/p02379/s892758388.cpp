#include<bits/stdc++.h>
using namespace std;

int main(){
  long double x1,y1,x2,y2;
  cin>>x1>>y1>>x2>>y2;
  //cout<<pow(pow(x2-x1,2)+pow(y2-y1,2),0.5)<<endl;
  cout<<std::setprecision(10)<<sqrt(x1*x1+y1*y1+x2*x2+y2*y2-(x1*x2+y2*y1)*2)<<endl;
  //cout<<hypot(x2-x1,y2-y1)<<endl;
}

