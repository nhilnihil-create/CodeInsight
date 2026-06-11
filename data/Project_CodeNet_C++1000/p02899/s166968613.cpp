#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){

  int N;
  cin>>N;
  vector<int>A(N);
  vector<int>A2(N);
  for(int i=0;i<=N-1;i++){
    cin>>A[i];
  }
  for(int i=0;i<=N-1;i++){
  
    A2[A[i]-1]=i+1;
  }
  for(int i=0;i<=N-1;i++){
  
    cout<<A2[i]<<" ";
  }
  return 0;
}