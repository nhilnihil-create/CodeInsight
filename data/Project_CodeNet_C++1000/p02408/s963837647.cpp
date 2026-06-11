#include<iostream>
using namespace std;
int main(void){
  int n,i,j,value;
  char symbol;
  int s[13],h[13],c[13],d[13];
  for(i=0;i<13;i++){
    s[i]=0;
    h[i]=0;
    c[i]=0;
    d[i]=0;
  }
  cin>>n;
  for(i=0;i<n;i++){
    cin>>symbol>>value;
    if(symbol=='S'){
      s[value-1]++;
    }else if(symbol=='H'){
      h[value-1]++;
    }else if(symbol=='C'){
      c[value-1]++;
    }else{
      d[value-1]++;
    }
  }
  for(i=0;i<13;i++){
    if(s[i]==0){
      cout<<"S "<<i+1<<endl;
    }
  }
  for(i=0;i<13;i++){
    if(h[i]==0){
      cout<<"H "<<i+1<<endl;
    }
  }
  for(i=0;i<13;i++){
    if(c[i]==0){
      cout<<"C "<<i+1<<endl;
    }
  }
  for(i=0;i<13;i++){
    if(d[i]==0){
      cout<<"D "<<i+1<<endl;
    }
  }
  return 0;
}