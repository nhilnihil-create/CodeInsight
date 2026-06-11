#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  ll n;
  cin >> n;
  map<ll,ll> mp;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
    mp[a[i]]++;
  }
  ll sum=0;
  for(int i=1; i<=n; i++){
    sum +=  mp[i]*(mp[i] - 1)/2;
  }
  rep(i,n){
    ll v = mp[a[i]];
    ll ans = sum - v*(v-1)/2 + (v-1)*(v-2)/2;
    cout << ans << endl;
  }
}
