#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
  int N,i,j,ans=0,M=0;
  cin>>N;
  vector<int> A(N),a(1000001);
  for(i=0;i<N;i++){
    cin>>A[i];
    a[A[i]]++;
    M=max(A[i],M);
  }
  sort(A.begin(), A.end());
  for(i=0;i<N;i++){
    if(a[A[i]]==1)ans++;
    for(j=2;A[i]*j<=M;j++)a[A[i]*j]=0; 
  }
  cout<<ans<<endl;
}