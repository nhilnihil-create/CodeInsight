#include<iostream>
#include<vector>
using namespace std;
int main(){

  int K,N;
  cin>>K>>N;
  vector<int>A(N);
  for(int i=0;i<=N-1;i++){
  
    cin>>A[i];
  }
  int max=-1;
  for(int i=0;i<=N-2;i++){
  
    if(max<A[i+1]-A[i])max=A[i+1]-A[i];
  }
  if(max<K-A[N-1]+A[0])max=K-A[N-1]+A[0];
  if(max<0)max=0;
  cout<<K-max;
  return 0;
}