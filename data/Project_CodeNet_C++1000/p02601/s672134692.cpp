#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b,c,k;
  cin>>a>>b>>c>>k;
  if(b>a){
  }
  else if(2*b>a){
    b=2*b;
    k=k-1;
  }
  else if(4*b>a){
    b=4*b;
    k=k-2;
  }
  else if(8*b>a){
    b=8*b;
    k=k-3;
  }
  else if(16*b>a){
    b=16*b;
    k=k-4;
  }
  else if(32*b>a){
    b=32*b;
    k=k-5;
  }
  else if(64*b>a){
    b=64*b;
    k=k-6;
  }
  else if(128*b>a){
    b=128*b;
    k=k-7;
  }
  if(c>b){
  }
  else if(2*c>b){
    k=k-1;
  }
  else if(4*c>b){
    k=k-2;
  }
  else if(8*c>b){
    k=k-3;
  }
  else if(16*c>b){
    k=k-4;
  }
  else if(32*c>b){
    k=k-5;
  }
  else if(64*c>b){
    k=k-6;
  }
  else if(128*c>b){
    k=k-7;
  }
  if(k<0){
    cout<<"No"<<endl;
  }
  else{
    cout<<"Yes"<<endl;
  }

}