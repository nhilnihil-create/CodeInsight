#include<iostream>
#include<cmath>
using namespace std;
bool EQ(double a,double b){
  return abs(a-b)<0.000000000001;
  //  return a-0.0000001<b&&b<a+0.0000001;
}
int main(){
  int n;
  double x[4],y[4];
  cin>>n;
  while(n--){
    for(int j=0;j<4;j++) cin>>x[j]>>y[j];
    if(EQ((y[3]-y[2])*(x[1]-x[0]),(y[1]-y[0])*(x[3]-x[2])))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}