#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll n,l;
  cin >> n >> l;
  
  vector<ll> v(n);
  rep(i, n)
    v[i] = l+i;
  
  ll sum = 0;
  rep(i, n)
    sum += v[i];
  
  
  rep(i ,n){
    if(v[i] == 0){
      cout << sum << endl;
      return 0;
    }
  }
  
  sort(v.begin(),v.end());
  
  if(sum >= 0)
    cout << sum - v[0] << endl;
  else
    cout << sum - v[n-1] << endl;
    
}