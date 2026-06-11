/*
	Created by : imay_10
	" It won't be EASY, but I'll make it "
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int mod = 1e9+7;
const ll inf = 1e18;
const double pi = 3.1415926535897932384626;

// Utility for fast exponentiation
ll mpow(ll a,ll b,ll m){
    ll res=1;
    //a%=m;
    while(b){
    	if(b%2) res=res*a%m;
		a=a*a%m;
		b/=2;
	}
	return res;
}

// Utility for modular inverse
ll inv(ll a,ll m){
	return mpow(a,m-2,m);
}

// Utility for GCD Calculation
ll gcd(ll a,ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}

void solve(){
	//code
	ll a,b;
	cin>>a>>b;
	cout<<(a*b)/(gcd(a,b));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();
 	return 0;
}
