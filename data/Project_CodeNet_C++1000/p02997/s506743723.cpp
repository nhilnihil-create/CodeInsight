#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K;
  cin>>N>>K;
  if(K*2>(N-2)*(N-1)){
    cout<<"-1"<<endl;
  }
  else{
    cout<<N*(N-1)/2-K<<endl;
    for(int i=1;i<N;i++){
      cout<<i<<" "<<N<<endl;
    }
    int x=(N-1)*(N-2)/2-K;
    int a=1,b=1;
    for(int i=0;i<x;i++){
      b++;
      if(b>=N){
        a++;
        b=a+1;
      }
      cout<<a<<" "<<b<<endl;
    }
  }
}