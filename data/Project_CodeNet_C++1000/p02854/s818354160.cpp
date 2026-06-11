#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
using ll = long long;
int main(){
  ll n;
  ll sum = 0;
  cin >> n;
  vector<ll> a(n);
  for(ll i=0;i<n;i++){
    cin >> a[i];
    sum += a[i];
  }
  ll temp = a[0];
  ll ans = abs(sum-2*temp);
  for(ll i=1;i<n-1;i++){
    temp+=a[i];
    ans = min(ans, abs(sum-2*temp));
  }
  cout << ans << endl;
  return 0;
}