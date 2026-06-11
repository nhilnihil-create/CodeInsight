#include<iostream>
#include<vector>
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
  	ll p=1e9+7;
  	ll n,b,r;
	cin >> n >> b;

  	r = n-b;
  	
  	for(ll i=1;i<=b;i++){
      cout << (combination(r+1,i,p)*combination(b-1,i-1,p))%p << endl;
    }
  	
  	
    return(0);
}