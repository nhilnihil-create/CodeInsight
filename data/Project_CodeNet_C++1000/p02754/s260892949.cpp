#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N,A,B;
  cin>>N>>A>>B;
  ll C = A+B;
  ll ans;
  if(N%C>=A) ans = N/C*A+A;
  else ans = N/C*A+N%C;
  cout<<ans<<endl;
}