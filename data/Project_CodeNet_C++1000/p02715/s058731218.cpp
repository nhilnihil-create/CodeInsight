#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

ll pow(ll a, ll x, ll p){
  	ll tmp=1;
  	while(x>0){
    	if(x%2 == 1){
          	tmp = (a*tmp)%p;
        }
      	a = (a*a)%p;
      	x /= 2;
    }
  	return(tmp);
}

int main(){
  int N,K;
  cin >> N >> K;
  vector<ll> gcd(K+1);
  for(int i=K;i>=1;i--){
    ll a=K/i;
    ll tmp = pow(a,N,mod);
    ll j=2;
    while(i*j<=K){
      tmp = tmp - gcd.at(i*j);
      if(tmp < 0){
        tmp = tmp + mod;
      }
      j++;
    }
    gcd.at(i) = tmp;
  }
  
  /*
  for(int i=1;i<gcd.size();i++){
    cout << gcd.at(i) << endl;
  }
  */
  
  ll ans=0;
  for(int i=1;i<=K;i++){
    ans = (ans + i*gcd.at(i) % mod) % mod;
  }
  
  cout << ans << endl;
  
  return(0);
}