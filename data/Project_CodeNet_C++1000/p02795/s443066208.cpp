#include<bits/stdc++.h>
using namespace std;

int main(){

  long long H, W, N, mx, i, Sum=0;
  cin>>H>>W>>N;
  mx=max(H, W);
  
  for(i=0;i<N;i++){
    Sum+=mx;
    if(Sum>=N){
      cout<<i+1<<endl;
      return 0;
    }
  }
  return -1;
}