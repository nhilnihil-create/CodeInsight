#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> cnt(n, 0);
  ll sum = 0;
  map<ll, ll> ma;
  for(int i=0; i<n; i++) cin >> a[i];
  
  for(int i=0; i<n; i++){
    ma[a[i]]++;
  }
  
  for(auto it:ma) sum += it.second*(it.second-1)/2;
  
  for(int i=0; i<n; i++){
    sum += cnt[i]*(cnt[i]-1)/2;
  }
  
  for(int i=0; i<n; i++){
    ll val = ma[a[i]];
    ll before = val*(val-1)/2;
    ll after =  (val-1)*(val-2)/2;
    cout << sum - before + after << endl;
  }

  return 0;
}