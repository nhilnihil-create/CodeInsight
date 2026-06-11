#include<bits/stdc++.h>
//#include<iostream>
using namespace std;

typedef long long ll;
const int N = 2000006;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	ll x = (a-1)/c,y = (b/c);
	ll ans = b-a+1;
	ans -= (y*c - x*c)/c;
	x = (a-1)/d;
	y = (b)/d;
	ans -= (y*d - x*d)/d;
	ll l = c*d;
	l /= (__gcd(c,d));
	x = (a-1)/l;
	y = (b)/l;
	ans += (y*l-x*l)/l;
	cout<<ans;
	
	return 0;
}
