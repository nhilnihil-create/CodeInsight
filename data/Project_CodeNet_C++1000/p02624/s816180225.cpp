#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9+7;
ll mod(ll x) {
	return (x%MOD + MOD) %MOD;
}
ll mul(ll a,ll b) {
	return mod(mod(a) * mod(b));
}

int main(){
	ll n;
	cin >> n;
	ll result = 0;
	for(int i = 1; i <= n ;i++ )
	{
		ll y = n/i;
		result += ((y * (y+1))/2) * i;
	}
	cout << result << endl;
	return 0;
}