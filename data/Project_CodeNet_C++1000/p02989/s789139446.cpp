#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  int A[N];
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  sort(A,A+N);
  cout<<A[N/2]-A[N/2-1]<<endl;
}