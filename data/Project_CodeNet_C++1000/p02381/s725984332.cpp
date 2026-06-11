#include <iostream>
#include <cmath>
using namespace std;

int main(){
 int n;
 double m,sig;

 while(1){
  cin >> n ;
  if(n==0)break;

  double s[n],sum=0;
  for(int i=0;i<n;i++){
   cin >> s[i] ;
   sum+=s[i];
  }

  m=sum/n;
  sum=0; 

  for(int i=0;i<n;i++){
   sum+=(s[i]-m)*(s[i]-m);
  }

  sig=sqrt(sum/n);

  cout << fixed << sig << endl;
 }

 return 0;
}