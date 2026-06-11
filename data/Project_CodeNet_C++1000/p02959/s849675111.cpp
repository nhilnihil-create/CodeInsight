#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N,ans=0;
  cin>>N;
  vector<int> A(N+1),B(N,0);
  for(int &i:A)cin>>i;
  for(int &i:B)cin>>i;
  for(int i=0;i<N;i++){
    if(A[i]>B[i])
      ans+=B[i];
    else{
      ans+=A[i];
      B[i]-=A[i];
      if(A[i+1]>B[i])
        ans+=B[i],A[i+1]-=B[i];
      else
        ans+=A[i+1],A[i+1]=0,B[i]-=A[i+1];
    }
  }
  cout<<ans<<endl;
}