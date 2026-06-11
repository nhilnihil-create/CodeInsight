#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  string S;
  cin>>S;
  int N=S.size();
  vector<int> A(N+1),B(N+1);
  A[0]=0,B[N]=0;
  for(int i=0;i<N;i++){
    if(S[i]=='<')
      A[i+1]=A[i]+1;
    else
      A[i+1]=0;
  }
  for(int i=N;i>0;i--){
    B[i-1]=B[i];
    if(S[i-1]=='>')
      B[i-1]=B[i]+1;
    else
      B[i-1]=0;
  }
  int k=0;
  for(int i=0;i<=N;i++)
    k+=max(A[i],B[i]);
  cout<<k<<endl;
}