#include<iostream>
using namespace std;
using ll = long long;

int main() {
  ll X,K,D,ans;
  cin>>X>>K>>D;
  X=abs(X);
  if (X/D>=K) ans = X-K*D;
  else if ((K-X/D)%2 == 0) ans = X%D;
  else ans = D-X%D;
  cout<<ans<<endl;
  return 0;
}
