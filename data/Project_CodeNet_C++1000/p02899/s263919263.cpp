#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)

int main() {
  ll n;
  cin >> n;
  vector<pair<ll,ll>> a(n);
  rep(i,n){
    int x;
    cin >> x;
    a[i] = make_pair(x,i+1);
  }
  
  sort(a.begin(),a.end());
  
  for(auto s : a){
    cout << s.second << " ";
  }
  cout << endl;
  
  return(0);
}