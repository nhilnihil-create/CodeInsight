#include<bits/stdc++.h>
#define int long long
using namespace std;
int N,K,sum=0;
vector<int> A;
bool a(int i){
  vector<int> B(N+1);
  for(int j=0;j<N;j++)B[j]=A[j]%i;
  sort(B.begin(),B.end());
  vector<int> C(N+1);
  for(int j=0;j<N;j++)C[j]=i-B[j+1];
  for(int j=0;j<N;j++)B[j+1]+=B[j],C[N-j-1]+=C[N-j];
  for(int j=0;j<N;j++)
    if(B[j]<=K && C[j+1]<=K)return true;
  return false;
}
signed main(){
  cin>>N>>K;
  A.resize(N);
  for(int &i:A){
    cin>>i;
    sum+=i;
  }
  int mx=0;
  for(int i=sqrt(sum);i>0;i--){
    if(sum%i)continue;
    if(a(i))mx=max(mx,i);
    if(a(sum/i))mx=max(mx,sum/i);
  }
  cout<<mx<<endl;
}