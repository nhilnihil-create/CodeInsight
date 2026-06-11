#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main( ){
  while(1){
    double n,s[1000],heikin=0,hensa=0;
    cin>>n;
    if(n==0)break;
    for(int i=0;i<n;i++){
      cin>>s[i];
    heikin+=s[i];
    }
    heikin/=n;
    for(int i=0;i<n;i++){
      s[i]=pow(s[i]-heikin,2);
      hensa+=s[i];
    }
    printf("%f\n",sqrt(hensa/n));
  }
  return 0;
}