#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int p(int A,int B){
  if(!B)return 1;
  if(B%2)return p(A,B-1)*A%mod;
  int C=p(A,B/2);
  return C*C%mod;
}
signed main(){
  int N;
  cin>>N;
  vector<int> D(N);
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin>>D[i];
    if((i==0 && D[i]!=0) || (i!=0 && D[i]==0)){
      puts("0");
      return 0;
    }
    A[D[i]]++;
  }
  int n=-1;
  for(int i=1;i<N;i++){
    if(A[i]==0)n=i;
    else if(n!=-1){
      puts("0");
      return 0;
    }
  }
  int ans=1;
  for(int i=1;i<n;i++)
    ans=ans*p(A[i-1],A[i])%mod;
  cout<<ans<<endl;
}