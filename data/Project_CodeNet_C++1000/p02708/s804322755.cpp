#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll n, k, min, max, ans=0;
  cin >> n >> k;
  
  vector<ll> sum(n+1,0);
  for(int i = 0; i < n+1; i++){
    if(i == 0) sum.at(i) = i;
    else sum.at(i) = sum.at(i-1) + i;
  }
  
  for(int i = k; i <= n+1; i++){
    ll min = sum.at(i-1);
    if(n-i >= 0) max = sum.at(n) - sum.at(n-i);
    else max = sum.at(n);
    ans += max - min + 1;
  }
  
  cout << ans%(10*10*10*10*10*10*10*10*10+7) << endl;
  
  return 0;
}