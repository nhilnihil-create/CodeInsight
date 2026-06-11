#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
 ll N;
  cin>>N;
  vector<ll> d(N);
  for(ll i=0;i<N;i++) {
cin>>d[i];
  }
  sort(all(d));
  ll i=N/2;
  cout<<d[i]-d[i-1]<<endl;
}

  

  
  
