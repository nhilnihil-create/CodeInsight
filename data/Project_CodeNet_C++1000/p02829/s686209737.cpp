#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
 ll A,B;
  cin>>A>>B;
  set<ll> S;
  S.insert(A);
  S.insert(B);
  for(ll i=1;i<=3;i++) {
if(!S.count(i)) {
cout<<i<<endl;
  return 0;
}
  }
}