#include<iostream>
using namespace std;
int main(){
  int S,W;
  cin>>S>>W;
  if(S>=1 && S<=100 && W>=1 && W<=100){
    if(S>W)
      cout<<"safe"<<endl;
    else
      cout<<"unsafe"<<endl;}
  return 0;}
