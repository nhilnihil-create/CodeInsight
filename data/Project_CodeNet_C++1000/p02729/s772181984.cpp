#include<bits/stdc++.h>
using namespace std;

int comb(int N,int two){
  if(two==1){
    return N;
  }
  else if(N==two||two==0){
    return 1;
  }
  else{
    return (comb(N-1,two-1)+comb(N-1,two));
  }
}

int main(){
  int N,M,sum_s=0,sum_m=0;
  cin>>N>>M;
  if(N>=2){
    sum_s=comb(N,2);
  }
  if(M>=2){
    sum_m=comb(M,2);
  }
  cout<<sum_s+sum_m<<endl;
}