#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int A,B;
  cin>>A>>B;
  ll ans = A;
  while(ans%B != 0) ans+=A;
  cout<<ans<<endl;
}