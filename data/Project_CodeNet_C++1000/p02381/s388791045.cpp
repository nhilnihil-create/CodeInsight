#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int a;
  for(int i=0;;i++){
    cin>>a;
    double b[1000]={0.0000000000},c=0.000000000,d=0.000000000;
    if(a==0)break;
    for(int j=0;j<a;j++){
        cin>>b[j];
        d+=b[j];
    }
    d=d/a;
    for(int j=0;j<a;j++){
        c+=(b[j]-d)*(b[j]-d);
    }
    c=c/a;
    cout <<setprecision(10)<<sqrt(c)<<endl;
  }
  return 0;
}