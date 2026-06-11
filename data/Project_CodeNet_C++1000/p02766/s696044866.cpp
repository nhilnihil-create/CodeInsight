#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,K,count=0;
  cin>>N>>K;
  while(N>=K){
    N/=K;
    count++;
  }
  cout<<(N==0?count:count+1)<<endl;
}