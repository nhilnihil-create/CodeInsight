#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
  ll n;
  cin>>n;
  ll count = 0;
  for(ll i=1;i<=n;i++){
    for(ll j=1;j<=n;j++){
      for(ll k=1;k<=n;k++){
        ll z = __gcd(i,j);
        z = __gcd(z,k);
        count = count + z;
      }
    }
  }
  cout<<count<<endl;
} 