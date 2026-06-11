#include<bits/stdc++.h>
using namespace std;
int N,K,l,r;
int main(){
  cin>>N>>K;
  vector<int>A(N);
  for(int i=0;i<N;i++)cin>>A[i];
  while(K--){
    vector<int>B(N+1,0);
    for(int i=0;i<N;i++){
      l=max(0,i-A[i]);
      r=min(N-1,i+A[i]);
      B[l]++;
      B[r+1]--;
    }
    bool changed=false;
    for(int i=0;i<N;i++){
      changed|=(A[i]!=B[i]);
      A[i]=B[i];
      B[i+1]+=B[i];
    }
    if(!changed)break;
  }
  for(int i=0;i<N;i++)cout<<A[i]<<" \n"[i==N-1];
}
