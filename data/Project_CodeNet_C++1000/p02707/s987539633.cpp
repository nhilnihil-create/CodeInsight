#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N;
  cin>>N;
  vector<ll> vec(N,0);
  for(ll i=0;i<N-1;i++) {
ll A;
    cin>>A;
    vec[A-1]++;
  }
  for(ll x:vec) {
cout<<x<<endl;
  }
}
