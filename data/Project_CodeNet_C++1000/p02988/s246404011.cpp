#include <bits/stdc++.h>
using namespace std;
 
#define FAST ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
 
#define MAXX 100005
 
#define PI   3.14159265358979323846264338327950

#define PB push_back 
#define F first
#define S second
 
#define ll 	 long long int

#define mod  1000000007


map<char, int> m;


int main()
{
	FAST;
	ll n;
	cin >> n;
	ll a[n+5];
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	} ll ans = 0;
	for(ll i = 1; i  + 1 < n ; i ++){
		ll x = min(a[i-1], min(a[i], a[i+1]));
		ll y = max(a[i-1], max(a[i], a[i+1]));
		ll z = a[i] + a[i-1] + a[i+1] - x - y;
		if(a[i] == z){
			ans ++;
		}
	}
	cout << ans;
	return 0;
}
