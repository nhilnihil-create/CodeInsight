#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int a,b,x;
  cin >> a >> b >> x;
  
  if(2*x<a*a*b){
    double l=0,r=90;   
    for(int i=0;i<10000;i++){
      double m=(l+r)/2;
      if(a*b*b*tan((90-m)/180*M_PI)/2<x) r=m;
      else l=m;
    }
    cout << fixed << setprecision(10);
    cout << r << endl;
        
      
  }
  else{
    double l=0,r=90;
    for(int i=0;i<10000;i++){
      double m=(l+r)/2;
      if(a*a*b-a*a*a*tan(m/180*M_PI)/2<x) r=m;
      else l=m;
    }
    cout << fixed << setprecision(10);
    cout << r << endl;
  }
}