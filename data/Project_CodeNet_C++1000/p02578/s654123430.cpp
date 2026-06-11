#include<bits/stdc++.h>
using namespace std;
 
int main(){
 unsigned long long N;
  cin>>N;
   unsigned long long  A[N];
   unsigned long long  sum=0;
  for( unsigned long long  i=0;i<N;i++){
    cin>>A[i];
  }
  for( unsigned long long  i=1;i<N;i++){
    if(A[i-1]>A[i]){
      sum+=A[i-1]-A[i];
      A[i]=A[i-1];
    }
  }
  cout<<sum<<endl;
}