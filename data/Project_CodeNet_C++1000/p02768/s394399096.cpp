#include <bits/stdc++.h>
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

ll inv(ll a, ll p){
  	return pow(a,p-2,p);
}

vector<ll> fact;
ll factorial(ll n, ll p){
  	ll res = 1;
  	for(ll i=1;i<=n;i++){
      	res = (res*i)%p;
    }
  	return res;
}

/*
ll combination(ll n, ll r, ll p){
    ll res=1;
  	ll tmp1 = fact.at(n);
  	ll tmp2 = fact.at(n-r);
  	ll tmp3 = fact.at(r);
  	res = ( ( (tmp1 * inv(tmp2,p) ) % p) * inv(tmp3,p) ) % p;
  	return res;
}
*/

ll combination(ll n, ll r, ll p){
  ll ans = 1;
  for(ll i=1;i<=r;i++){
    ll x = (n+1-i)*inv(i,p) % p;
    ans = (ans * x) % p; 
  }
  return(ans);
}

int main(){
  ll n,a,b;
  cin >> n >> a >> b;
  
  //cout << combination(5,3,7) << endl;
  
  ll ans=pow(2,n,mod)-1;
  
  ll ban_a = combination(n,a,mod);
  ll ban_b = combination(n,b,mod);
  
  if(ans < ban_a){
    ans = (mod + ans - ban_a) % mod;
  }else{
    ans = (ans - ban_a) % mod;
  }
  
  if(ans < ban_b){
    ans = (mod + ans - ban_b) % mod;
  }else{
    ans = (ans - ban_b) % mod;
  }
  
  cout << ans << endl;
  
  return(0);
}