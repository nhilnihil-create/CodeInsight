#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll n, k;
  cin >> n >> k;
  
  vector<ll> h(n);
  for(ll i=0; i<n; i++) cin >> h[i];
  sort(h.rbegin(), h.rend());
  
  
  for(ll i=0; i<k; i++){
    h[i] = 0;
    if(i+1==n) break;
  }
  
  ll sum = 0;
  cout << accumulate(h.begin(), h.end(), sum) << endl;
  
  return 0;
}