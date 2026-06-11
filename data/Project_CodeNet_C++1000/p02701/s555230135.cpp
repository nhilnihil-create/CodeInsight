#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  string A[N];
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  int sum =1;
  sort(A,A+N);
  for(int i=0;i<N-1;i++){
    if(A[i]!=A[i+1]){
      sum++;
    }
  }
  cout<<sum<<endl;
}