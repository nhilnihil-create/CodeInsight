#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int N,K;
  cin>>N>>K;
  vector<int> A(N);
  rep(i,N)cin>>A[i];
  rep(j,K){
    vector<int> B(N+1);
    rep(i,N){
      int L=max(0,i-A[i]);
      int R=min(i+A[i]+1,N);
      B[L]++;
      B[R]--;
    }
    rep(i,N)B[i+1]+=B[i];
    B.pop_back();
    if(A==B) break;
    A=B;
  }
  rep(i,N)cout<<A[i]<<endl;
  return 0;
}