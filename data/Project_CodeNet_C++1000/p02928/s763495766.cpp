#include <bits/stdc++.h>
using namespace std;
int main(){
  long long int N,K,X=0,M=1000000007;
  cin>>N>>K;int A[N];
  for(int i=0;i<N;i++)cin>>A[i];
  for(int i=0;i<N;i++){
    long long int S=0,T=0;
    for(int j=0;j<i;j++)if(A[i]>A[j])S++;
    for(int j=i;j<N;j++)if(A[i]>A[j])T++;
    X+=K*(K+1)/2%M*T%M+K*(K-1)/2%M*S%M;X%=M;
  }
  cout<<X<<endl;
}