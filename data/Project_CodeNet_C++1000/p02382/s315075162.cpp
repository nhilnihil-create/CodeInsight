#include<iostream>
#include <math.h>
using namespace std;
int main(){
  int n,x[100],y[100];
  double ma=0,eu=0,m3=0,ch=0,di;
  cin>>n;
  for(int i=0;i<n;i++) cin>>x[i];
  for(int i=0;i<n;i++) cin>>y[i];
  for(int i=0;i<n;i++){
    di = fabs(x[i]-y[i]);
    ma += di;
    eu += di*di;
    m3 += di*di*di;
    if(ch<di) ch = di;
  }
  cout<<fixed<<ma<<endl<<sqrt(eu)<<endl<<pow(m3,1./3)<<endl<<ch<<endl;
}