#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<int>A(N);
  int Sum=0;
  for(int i=0;i<N;i++){
    cin>>A[i];
    Sum^=A[i];
  }
  for(int i=0;i<N;i++){
    cout<<(Sum^A[i])<<" ";
  }
}