//itp1_10d
#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
 double m1,m2,m3,m4,temp;
 int n;
 cin>>n;
 vector<int> x(n,0);
 vector<int> y(n,0);
 for(int i=0;i<n;i++)
  cin>>x[i];
 for(int i=0;i<n;i++)
  cin>>y[i];
 m1=0;
 for(int i=0;i<n;i++)
  m1+=1.0*abs(x[i]-y[i]);
 temp=0;
 for(int i=0;i<n;i++){
  temp+=1.0*(x[i]-y[i])*(x[i]-y[i]);
  m2=pow(temp,1.0/2.0);
 }
 temp=0;
 for(int i=0;i<n;i++){
  int j=abs(x[i]-y[i]);
  temp+=j*j*j;
  m3=pow(temp,1.0/3.0);
 }
 temp=0;
 for(int i=0;i<n;i++){
  int j=abs(x[i]-y[i]);
  if(j>temp)
   temp=j;
  }
  m4=temp;
 printf("%.6f\n",m1);
 printf("%.6f\n",m2);
 printf("%.6f\n",m3);
 printf("%.6f\n",m4);

 return 0;
}