#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll n;
  cin >> n;
  
  vector<ll> a(n);
  for(ll i=0; i<n; i++) cin >> a[i];
  
  int num = 1;
  for(ll i=0; i<n; i++){
    if(num==a[i]){
      num++;
    }
  }
 
  if(num==1) cout << -1 << endl;
  else cout << n-num+1 << endl;
  
  return 0;
}