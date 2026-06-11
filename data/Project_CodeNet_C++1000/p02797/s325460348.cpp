#include<bits/stdc++.h>
using namespace std;

int main(){

  long long N, K, S;
  cin>>N>>K>>S;
  
  for(long long i=0; i<N; i++){
    
    if(i<K){
      cout<<S<<" ";
    }else{
      if(S==1000000000){
        cout<<999999999<<" ";
      }else{
        cout<<1000000000<<" ";
      }
    }
  }
  return 0;
}