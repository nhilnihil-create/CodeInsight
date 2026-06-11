//itp1_10c
#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
 while(true){
  int n;
  cin>>n;
  if(n==0) break;
  vector<int> v(n,0);
  int sum=0;
  double sumd=0;
  double a,aa;
  for(int i=0;i<n;i++)
   cin>>v[i];
  for(int i=0;i<n;i++)
    sum+=v[i];
  double ave=1.0*sum/n;
  for(int i=0;i<n;i++)
   sumd+=(v[i]-ave)*(v[i]-ave);
  aa=sumd/n;
  a=sqrt(aa);
  printf("%.8f\n",a);
 }
  
 return 0;
}