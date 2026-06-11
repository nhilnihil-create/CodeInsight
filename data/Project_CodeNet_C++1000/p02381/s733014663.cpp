#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main(){
 int n;
 double a,m,sum;
 while(1){
  cin >> n;
  int s[n+1]={};
  if(n==0) break;

  sum=0;
  for(int i=0;i<n;++i){
   cin >> s[i];
   sum+=s[i];
  }
  m=sum/n;

  a=0;
  for(int i=0;i<n;++i){
   a+=pow(s[i]-m,2);
  }
  a=sqrt(a/n);
  cout << fixed << setprecision(8) << a << endl ;
 }
 return 0;
}