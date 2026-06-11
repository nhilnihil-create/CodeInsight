#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
  //int sum = 0,
  int x[1000],y[1000],n;
  //double max = 0;
  double p1 = 0,p2 = 0,p3 = 0,p = 0;
  cin>>n;
  for(int i = 0;i < n;i++){
    cin>>x[i];
  }
  for(int i = 0;i < n;i++){
    cin>>y[i];
  }
  for(int i = 0;i < n;i++){
    p1 += abs(x[i]-y[i]);
    if(x[i]-y[i] < 0){
      p2 += pow(((x[i]-y[i])*-1),2.0);
    }else{
      p2 += pow(x[i]-y[i],2.0);
    }
    if(x[i]-y[i] < 0){
      p3 += pow(((x[i]-y[i])*-1),3.0);
    }else{
      p3 += pow((x[i]-y[i]),3.0);
    }
    if(abs(x[i]-y[i])>p){
      p = abs(x[i]-y[i]);
    }
  }
  p2 = sqrt(p2);
  p3 = pow(p3,1.0/3.0);
  cout<<fixed<<setprecision(5)<<p1<<endl;
  cout<<fixed<<setprecision(5)<<p2<<endl;
  cout<<fixed<<setprecision(5)<<p3<<endl;
  cout<<fixed<<setprecision(5)<<p<<endl;
  return 0;
}