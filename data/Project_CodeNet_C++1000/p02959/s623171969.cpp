#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
#define ll long long
#define ld long double
     
int main(){
  ll n; cin >> n;
  vector<ll> a(n+1); rep(i,n+1) cin >> a[i];
  vector<ll> b(n);   rep(i,n) cin >> b[i];
  
  ll destroy = 0;
  for(ll i = 1; i <= b.size(); i++){
    ll enemySum = a[i-1] + a[i];
    if(enemySum>=b[i-1]){
      destroy += b[i-1];
      if(a[i-1]<b[i-1]){a[i] -= (b[i-1]-a[i-1]); a[i-1] = 0;}
    }else{
      destroy += (a[i-1]+a[i]);
      a[i-1] = 0; a[i] = 0;
    }
  }
  cout << destroy << endl;
}