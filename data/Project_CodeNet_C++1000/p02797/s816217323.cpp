#include <bits/stdc++.h>
using namespace std;


int main() {
  int64_t N,K,S;
  cin>>N>>K>>S;
  
  if(S==1000000000){
    for(int i=0;i<K;i++){
      cout<<1000000000<<endl;
    }
    for(int i=0;i<N-K;i++){
      cout<<1<<endl;
    }
  }
  else{
    for(int i=0;i<K;i++){
      cout<<S<<endl;
    }
    for(int i=0;i<N-K;i++){
      cout<<1000000000<<endl;
    }
  }
  
}