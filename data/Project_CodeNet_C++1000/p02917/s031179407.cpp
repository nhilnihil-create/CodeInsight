#include<iostream>
#include<vector>
using namespace std;
int main(){

  int N;
  cin>>N;
  vector<int>B(N-1);
  vector<int>A(N,999999);
  for(int i=0;i<=N-2;i++){
  
    cin>>B[i];
  }
  for(int i=0;i<=N-2;i++){
  
    if(A[i+1]>B[i])A[i+1]=B[i];
    if(A[i]>B[i])A[i]=B[i];
  }
  int ans=0;
  for(int i=0;i<=N-1;i++){
  
    ans+=A[i];
  }
  cout<<ans;
  return 0;
}