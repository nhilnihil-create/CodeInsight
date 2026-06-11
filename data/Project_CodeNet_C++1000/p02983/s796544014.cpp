#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0;i < (n);i++)
#define all(v) v.begin(),v.end()
#define dec(n) cout << fixed << setprecision(n);
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vl>;

ll gcd(ll a,ll b){
  if(b == 0) return a;
  return gcd(b , a % b);
}

ll mod(ll a){
  return (a % 1000000007);
}

ll lcm(ll a,ll b){
  return (a*b)/gcd(a,b);
}


int main(){
  ll l,r; cin >> l >> r; ll ans = 2018;
  
  if(r-l <= 2019){
    for(ll i=l; i <= r; i++){
      for(ll j=l; j <= r; j++){
       
        if(i != j){
          ans = min(ans,(i*j) % 2019);
        }
      }
    }
  }
  
  else{
    for(ll i=l; i <= l+2019; i++){
      for(ll j=l; j <= l+2019; j++){
        
        if(i != j){
          ans = min(ans,(i*j) % 2019);
        }
      }
    }
  }
  
  cout << ans << endl;
  
}
  
  