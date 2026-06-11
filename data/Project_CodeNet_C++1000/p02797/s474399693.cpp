#include<bits/stdc++.h>
using namespace std;
int main(){
int N,K,S;
  cin>>N>>K>>S;
  vector<int>A(N);
  for(int i=0;i<K;i++)
    A.at(i)=S;
  for(int i=K;i<N;i++){
  if(S==1000000000){
  A.at(i)=3;
  }else{A.at(i)=1+S;}
  
  }for(int i=0;i<N;i++)
    cout<<A.at(i)<<endl;
   return 0;
}