#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  long long  A[n];
  long long ans=0;
  for(int i=0;i<n;i++){
    cin>>A[i];
  }
  sort(A,A+n);
  ans=A[n-1];
  for(int i=0;i<n-2;i++){
    ans+=A[n-2-i/2];
    //cout<<ans<<endl;
  }
  cout<<ans<<endl;
  return 0;
}

    
  
  