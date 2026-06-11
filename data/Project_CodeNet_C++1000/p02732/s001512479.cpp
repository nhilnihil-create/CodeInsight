#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
  int N; cin>>N;
  vector<int>A(N);
  vector<long long>B(N);
  long long ans=0;
  rep(i,N){
    cin>>A[i];
    B[A[i]-1]++;
  }
  rep(i,N)ans+=B[i]*(B[i]-1)/2;
  rep(i,N)cout<<ans-B[A[i]-1]+1 <<endl;
}