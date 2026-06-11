#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
  long long int n,a,b,res;
  cin>>n;
  res=n+1;
  for(int i=2;i<=sqrt(n);i++){
    if(n%i==0){
      b=n/i;
      a=i;
      res=min(res,a+b);
    }
  }
  cout<<res-2;
  return 0;
}
