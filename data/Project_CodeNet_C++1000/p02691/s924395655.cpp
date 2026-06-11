#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin>>N;
  vector<int> A(N),B(N+1,0);
  ll i;
  for (i=0;i<N;i++) {
    cin>>A[i];
    if (i+1+A[i]<=N) {
      B[i+1+A[i]]++;
    }
  }
  ll ans=0;
  for (i=0;i<N;i++) {
    if (i+1>=A[i]) {
      ans += B[i+1-A[i]];
    }
  }
  cout<<ans<<endl;
  return 0;
}
