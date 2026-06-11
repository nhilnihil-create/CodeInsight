#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N,K;
  cin>>N>>K;
  vector<int> A(N+1);
  A[0]=0;
  for(int i=0;i<N;i++){
    int p;
    cin>>p;
    A[i+1]=A[i]+p+1;
  }
  int j=0;
  for(int i=0;i<=N-K;i++)
    j=max(j,A[i+K]-A[i]);
  cout<<fixed<<setprecision(1)<<j/(long double)2<<endl;
}