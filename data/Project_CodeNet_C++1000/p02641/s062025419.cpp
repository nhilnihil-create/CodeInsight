#include <bits/stdc++.h>
using namespace std;

int main() {
  int x,n,c,b;
  cin>>x>>n;
  c=x;
  b=x;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a.at(i);
  }
  int flag=0;
  for(int i=0;i<x;i++){
    for(int j=0;j<n;j++){
      if(x-i==a.at(j)){
        break;
      }
      if(j==n-1){
        c=i;
        flag=1;
      }
      if(flag==1){
        break;
      }
    }
  }
  flag=0;
  for(int i=0;i<x;i++){
    for(int j=0;j<n;j++){
      if(x+i==a.at(j)){
        break;
      }
      if(j==n-1){
        b=i;
        flag=1;
      }
      if(flag==1){
        break;
      }
    }
  }
  if(n==0){
    cout<<x;
  }else if(c<=b){
    cout<<x-c;
  }else{
    cout<<x+b;
  }
}