#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

int main() {
  int N,i;
  cin>>N;
  vector<int> A(N);
  for (i=0;i<N;i++) {
    cin>>A[i];
  }
  sort(A.begin(), A.end());
  ll ans=A[N-1];
  for (i=2;i<N;i++) {
    ans+=A[N-1-i/2];
  }
  cout<<ans<<endl;
  return 0;
}
