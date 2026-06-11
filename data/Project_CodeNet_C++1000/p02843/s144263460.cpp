#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int X;cin>>X;
  
  if(X>=2000){
    cout<<1<<endl;
  }
  else{
    for(int i=0;i<21;i++){
      for(int j=0;j<20;j++){
        for(int k=0;k<20;k++){
          for(int l=0;l<20;l++){
            for(int m=0;m<20;m++){
              for(int n=0;n<20;n++){
  if(100*i+101*j+102*k+103*l+104*m+105*n==X){
    cout<<1<<endl;
    return 0;
  }
              }
            }
          }
        }
      }
    }
  
  cout<<0<<endl;
  }
}