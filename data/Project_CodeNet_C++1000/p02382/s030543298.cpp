#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main(){
 int n;
 double d1,d2,d3,dinf;
 cin >> n;
 int x[n]={};
 int y[n]={};

 for(int i=0;i<n;++i){
  cin >> x[i];
 }
 for(int i=0;i<n;++i){
  cin >> y[i];
 }

 dinf=0.0;
 for(int i=0;i<n;++i){
  d1+=fabs(x[i]-y[i]);
  d2+=pow(x[i]-y[i],2);
  d3+=pow(fabs(x[i]-y[i]),3);
  
  if(fabs(x[i]-y[i])>dinf){
   dinf=fabs(x[i]-y[i]);
  }
 }

 d2=sqrt(d2);
 d3=pow(d3,1.0/3.0);

 cout << fixed << setprecision(8) << d1 << endl << d2 << endl << d3 << endl << dinf << endl;
 return 0;
}