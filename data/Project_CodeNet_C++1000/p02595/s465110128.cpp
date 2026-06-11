#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

int main() {
  int N,i,ans=0;
  ll D;
  cin>>N>>D;
  vector<ll> X(N),Y(N);
  for (i=0;i<N;i++) {
    cin>>X[i]>>Y[i];
    if (X[i]*X[i] + Y[i]*Y[i] <= D*D) ans++;
  }
  cout<<ans<<endl;
  return 0;
}
