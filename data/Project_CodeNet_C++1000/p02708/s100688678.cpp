#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define modP 1000000007
#define MAX_N 200002

using namespace std;
typedef long long int ll;
ll ifac[MAX_N];
ll fac[MAX_N];

ll myPower(ll x,ll n){
	if(n == 0) return 1;
	if( n % 2 == 0){
		return myPower(x*x%modP,n/2);
	}else{
		return myPower(x,n-1)*x % modP;
	}
}

ll comb(ll a,ll b){
	if(a == 0 && b == 0) return 1;
	if( a < b || a < 0) return 0;
	ll tmp = ifac[a-b]*ifac[b]%modP;
	return tmp * fac[a]%modP;
}

void combInit(){
	fac[0] = 1;
	ifac[0] = 1;
	for(ll i = 0; i < MAX_N; i++){
		fac[i+1] = fac[i]*(i+1) % modP;
		ifac[i+1] = ifac[i]*myPower(i+1,modP - 2) % modP;
	}
}

int main(){
	ll N,K;
	cin>>N>>K;
	ll ans = 0;
	for(ll i = K; i <= N+1; i++){
		ll minSum = i*(i-1)/2;
		ll right = N;
		ll left = (N-i+1);
		ll maxSum = (right + left)*i/2;
		ans += maxSum - minSum + 1;
		ans = ans % modP;
	}
	cout<<ans<<endl;
	return 0;
}
