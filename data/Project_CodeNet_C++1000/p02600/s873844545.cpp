#include <bits/stdc++.h>
using namespace std;
int main(){
int x;
  cin>>x;
  if(x<=599){
  cout<<"8";
  }
  else if(x<=799){
    cout<<"7";
  }
  else if(x<=999){
    cout<<"6";
  }
  else if(x<=1199){
    cout<<"5";
  }
  else if(x<=1399){
    cout<<"4";
  }
  else if(x<=1599){
    cout<<"3";
  }
  else if(x<=1799){
    cout<<"2";
  }
  else{
    cout<<"1";
  }
}