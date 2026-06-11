#include<iostream>
using namespace std;
main(){
  int N,K,f,r=0;
  cin>>N>>K;
  for(int i=0;i<N;i++){
    cin>>f;
    if(f>=K) r=r+1;
  }
  cout<<r<<endl;
  return 0;
}