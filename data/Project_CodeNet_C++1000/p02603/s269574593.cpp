#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int main(){
  int n; cin >>n;
  vector<int> a(n);
  ll ans = 1000;
  rep(i,n) cin >>a[i];
  rep(i,n-1){
    ll stocks = 0;
    if(a[i]<a[i+1]) stocks = ans/a[i];
    ans += (a[i+1]-a[i])*stocks;
  }
  cout << ans << endl;
  return 0;
}