#include <iostream>
#include <cmath>
using namespace std;

int main(){
 int n;
 double p[3],max=0,sum; 

 cin >> n ;
 double x[n],y[n];
 for(int i=0;i<n;i++){
  cin >> x[i] ;
 }
 for(int i=0;i<n;i++){
  cin >> y[i] ;
 }

 for(int j=1;j<4;j++){
  sum=0;
  for(int i=0;i<n;i++){
   sum+=pow(fabs(x[i]-y[i]),j) ;
  }
  p[j-1]=(double)pow(sum,1.0/j);
 }

 for(int i=0;i<n;i++){
  if(fabs(x[i]-y[i])>max) max=double(fabs(x[i]-y[i]));
 }

 cout << fixed << p[0] << endl << p[1] << endl << p[2] << endl << max << endl;

 return 0;
}