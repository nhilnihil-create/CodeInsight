#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int main(){
  ll n,l[4000]; cin >>n;
  for(int i = 1; i<=n; i++) cin >>l[i];
  vector<ll> v(n);
  rep(i,n) v[i]=l[i+1];
  sort(v.begin(), v.end());
  ll ans = 0;
  for(ll mid = n-1; mid>=0; mid--){
    for(ll low = mid-1; low>=0; low--){
      auto itr = lower_bound(v.begin(), v.end(), v[mid]+v[low]);
      ll ng = distance(itr, v.end());
      ans += (n-1-mid)-ng;
    }
  }
  cout << ans << endl;
  return 0;
}