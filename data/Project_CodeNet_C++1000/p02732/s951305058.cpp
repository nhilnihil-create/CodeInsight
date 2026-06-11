#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }
  vector<ll> b(n);
  rep(i,n){
    ll x;
    x = a[i];
    b[x-1]++;
  }
  ll ans = 0;
  rep(i,n){
    ll y;
    y = b[i];
    ll z;
    if(y == 0 || y == 1){
      z = 0;
    }
    else{
      z = y * (y-1) / 2;
    }
    ans = ans + z;
  }
  
  rep(i,n){
    ll p;
    if(b[a[i]-1] == 0){
      p = 0;
    }
    else{
    p = b[a[i]-1] - 1;
    }
    cout << ans - p << endl;
  }
  
    
  return 0;
}


