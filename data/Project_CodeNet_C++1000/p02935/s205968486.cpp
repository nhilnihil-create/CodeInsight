#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
 double A[N];
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  for(int i=0;i<N-1;i++){
    sort(A,A+N);
    A[0]=(A[0]+A[1])/2;
    A[1]=1001;
  }
  cout<<A[0]<<endl;
}