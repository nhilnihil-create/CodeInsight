#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1000000007;
int p(int A,int B){
  if(!B)return 1;
  if(B&1)return p(A,B-1)*A%mod;
  int C=p(A,B/2);
  return C*C%mod;
}
int k[100100];
int c(int A,int B){
  if(A<B || B<0)return 0;
  return k[A]*p(k[A-B],mod-2)%mod;
}
signed main(){
  k[0]=1;
  for(int i=1;i<=100000;i++)k[i]=k[i-1]*i%mod;
  int N,K;
  cin>>N>>K;
  vector<vector<int>> A(N);
  for(int i=0;i<N-1;i++){
    int a,b;
    cin>>a>>b;
    A[a-1].push_back(b-1);
    A[b-1].push_back(a-1);
  }
  queue<int> Q;
  Q.push(0);
  vector<bool> B(N,true);
  B[0]=false;
  int ans=K*c(K-1,A[0].size())%mod;
  while(!Q.empty()){
    int I=Q.front();
    Q.pop();
    for(int i:A[I])
      if(B[i]){
        ans=ans*c(K-2,(int)A[i].size()-1)%mod;
        B[i]=false;
        Q.push(i);
      }
  }
  cout<<ans<<endl;
}