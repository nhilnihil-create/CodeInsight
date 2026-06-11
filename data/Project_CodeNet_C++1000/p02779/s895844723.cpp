#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll n;
  cin >> n;
  vector<ll> v(n);
  rep(i, n)
    cin >> v.at(i);
  sort(v.begin(),v.end());
  
  bool ans = false;
  
  rep(i, n-1){
    if(v.at(i) == v.at(i+1))
      ans = true;
  }
  if(ans)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
}