#include<iostream>
using namespace std;
using ll = long long;

int main() {
  ll A,B,N,ans;
  cin>>A>>B>>N;
  if (B<=N) {
    ans = A*(B-1)/B;
  } else {
    ans = A*N/B;
  }
  cout<<ans<<endl;
  return 0;
}
