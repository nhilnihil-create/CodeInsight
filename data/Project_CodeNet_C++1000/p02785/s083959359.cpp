#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,M;cin>>N>>M;
  vector<long long>A(N);
  for(int i=0;i<N;i++)cin>>A[i];
  sort(A.begin(),A.end());
  long long ans=0;
  for(int i=0;i<N-M;i++)ans+=A[i];
  cout<<ans<<endl;
}