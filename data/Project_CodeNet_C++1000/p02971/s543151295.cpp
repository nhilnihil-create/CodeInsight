#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  int A[N];
  int B[N];
  for(int i=0;i<N;i++){
    cin>>A[i];
    B[i]=A[i];
  }
  sort(A,A+N);
  reverse(A,A+N);
  for(int i=0;i<N;i++){
    if(B[i]==A[0]){
      cout<<A[1]<<endl;
    }else{
      cout<<A[0]<<endl;
    }
  }
}
