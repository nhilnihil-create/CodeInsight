#include <bits/stdc++.h>
using namespace std;

int main(){
  long long int i,x,j4,j5,kari,hantei,kotae=0;
  cin>>x;
  j4=pow(x,0.25);
  j5=pow(x,0.2);
  for(i=1;i<j5;i++){
    kari=x-pow(i,5);
    hantei=pow(kari,0.2);
    if(kari==pow(hantei,5)){
      cout<<i<<" "<<hantei*(-1);
      return 0;
    }
  }
  for(i=j5;i<=j4;i++){
    kari=pow(i,5)-x;
    hantei=pow(kari,0.2);
    if(kari==pow(hantei,5)){
      cout<<i<<" "<<hantei;
      return 0;
    }
  }
}