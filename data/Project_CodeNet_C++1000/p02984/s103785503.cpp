#include <bits/stdc++.h>  
using namespace std;
#define rep(i,n) for(ll i=0; i<(ll)(n); i++)
using ll = long long int;
 

int main() {
  ll n; cin>>n;
  ll sum = 0, m = 0;
  vector<ll> v(n);
  rep(i,n){
    cin>> v[i];
    sum += v[i];
    if(i % 2 == 1){m+= v[i];}
  }
  sum /= 2;  
  ll x = sum - m;
  cout<< 2 * x << " ";
  rep(i, n - 1){
    x= v[i] - x;
    cout << 2 * x << " ";
  }
}