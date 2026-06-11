#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstdio>
using namespace std;
int main(){

  while(1){
    double n,sum=0,a[1000];
    double av=0,s=0;
    cin>>n;
    if(n==0)break;
  for(int i=0;i<n;i++){
    cin>>a[i];
    sum+=a[i];
  }
  av=sum/n;
  for(int i=0;i<n;i++){
    s+=pow(a[i]-av,2);
  }
  s/=n;
  //printf("%.10f\n",sqrt(s));
  cout<<setprecision(10)<<sqrt(s)<<endl;
  }
  return 0;
  
}
