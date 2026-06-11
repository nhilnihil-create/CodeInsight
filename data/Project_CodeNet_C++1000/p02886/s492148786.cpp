#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

#define MAXX 500005
#define PI 3.14159265358979323846264338327950
#define F first
#define S second
#define ll   long long int
#define mod  1000000007



int main()
{
	FAST;
	ll n;
	cin >> n;
	ll a[n+3];
	for(ll i = 0; i < n; i ++){
		cin >> a[i];
	}
	ll ans = 0;
	for(ll i = 0; i < n-1; i ++){
		for(ll j = i + 1; j < n; j ++){
			ans += (a[i] * a[j]);
		}
	}
	cout << ans;
	
}