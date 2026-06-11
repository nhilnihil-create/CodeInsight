#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <cmath>
#include <queue>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const ll M = 1000000000 + 7;
#define MAX_N 1000000

vector<ll> fac(MAX_N+1);
vector<ll> ifac(MAX_N+1);

ll mpow(ll x,ll n){
	if(n == 0) return 1;
	if( n % 2 == 0) return mpow(x*x % M,n/2);
	return (mpow(x,n-1)*x) % M;
}

void combInit(){
	fac[0] = 1;
	ifac[0] = 1;
	for(ll i = 0; i < MAX_N; i++){
		fac[i+1] = fac[i]*(i+1) % M;
		ifac[i+1] = ifac[i]*mpow(i+1,M-2) % M;
	}
}

ll comb(ll a,ll b){
	if(a==0 && b == 0) return 1;
	if(a < b || a < 0) return 0;
	ll tmp = ifac[a-b] * ifac[b] % M;
	return tmp * fac[a]%M;
}

int main()
{
	ll X,Y;
	cin>>X>>Y;
	ll a,b;
	a = (2*X - Y)/3;
	b = (2*Y - X)/3;
	combInit();
	if( (2*X - Y) >= 0 && (2*Y - X) >= 0 && (2*X - Y) % 3 == 0 && (2*Y - X) % 3 ==0){
		cout<<comb((a+b),a)<<endl;
	}else{
		cout<<0<<endl;
	}
	
	return 0;
}

