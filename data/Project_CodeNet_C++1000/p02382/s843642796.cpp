#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#define lp(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
  int n;
  double x[101],y[101],ans1=0,ans2=0,ans3=0,ans4=0;
  cin>>n;
  lp(i,n){
    cin>>x[i];
  }
  lp(i,n){
    cin>>y[i];
  }
  lp(i,n){
    ans1+=fabs(x[i]-y[i]);
    ans2+=pow(fabs(x[i]-y[i]),2);
    ans3+=pow(fabs(x[i]-y[i]),3);
    ans4=max(ans4,fabs(x[i]-y[i]));
    
  }
  ans2=pow(ans2,1.0/2);
  ans3=pow(ans3,1.0/3);

  cout<<setprecision(10)<<ans1<<endl<<ans2<<endl<<ans3<<endl<<ans4<<endl;

  
  return 0;
  
}
