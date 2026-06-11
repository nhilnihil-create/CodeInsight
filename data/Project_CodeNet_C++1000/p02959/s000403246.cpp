#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >>n;
  long long A[n+1];
  long long B[n];
  for(int i=0;i<=n;i++){
    cin>>A[i];
  }
  for(int i=0;i<n;i++){
    cin>>B[i];
  }
  long long ans=0;
  for(int i=0;i<n;i++){
    if(B[i]>A[i]){
      ans+=A[i];
      ans+=min((B[i]-A[i]),A[i+1]);
      A[i+1]=A[i+1]+A[i]-B[i];
      if(A[i+1]<0){
        A[i+1]=0;
      }
    }
    else{
      ans+=B[i];
    }
  }
  cout<<ans<<endl;
  return 0;
}

