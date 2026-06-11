#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  cin>>a>>b;
  if(a==1&&b==1)cout<<1000000<<endl;
  else if(a==1){
    if(b==2){
      cout<<500000<<endl;
    }
    else if(b==3){
      cout<<400000<<endl;
    }
    else{
      cout<<300000<<endl;
    }
  }
  else if(a==2){
    if(b==1){
      cout<<500000<<endl;
    }
    else if(b==2){
      cout<<400000<<endl;
    }
    else if(b==3){
      cout<<300000<<endl;
    }
    else{
      cout<<200000<<endl;
    }
  }
  else if(a==3){
    if(b==1){
      cout<<400000<<endl;
    }
    else if(b==2){
      cout<<300000<<endl;
    }
    else if(b==3){
      cout<<200000<<endl;
    }
    else{
      cout<<100000<<endl;
    }
  }
  else{
    if(b==1){
      cout<<300000<<endl;
    }
    else if(b==2){
      cout<<200000<<endl;
    }
    else if(b==3){
      cout<<100000<<endl;
    }
    else{
      cout<<0<<endl;
    }
  }
}