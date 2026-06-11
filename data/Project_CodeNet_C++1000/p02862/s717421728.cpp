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

ll combination(ll n, ll r, ll p){
  	ll res=1;
  	ll tmp1 = factorial(n,p);
  	ll tmp2 = factorial(n-r,p);
  	ll tmp3 = factorial(r,p);
  	res = ( ( (tmp1 * inv(tmp2,p) ) % p) * inv(tmp3,p) ) % p;
  	return res;
}

int main(){
    ll X,Y;
  	cin >> X >> Y;
  	if((X+Y)%3!=0){
		cout << 0 << endl;
      	return(0);
    }

  	ll a,b;
  	a = (-X+2*Y)/3;
  	b = (2*X-Y)/3;
  	if(a < 0 || b < 0){
      	cout << 0 << endl;
      	return(0);
    }
    //cout << a << " " << b << endl;
  	cout << combination(a+b,a,mod) << endl;
  	
    return(0);
}