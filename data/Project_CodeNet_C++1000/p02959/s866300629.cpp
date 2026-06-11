#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
const int maxn = 1e9 + 5;
#define INF 1000000000
const int MOD = 1e9+7;
const double PI = 3.14159265358979323846264338;



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio	
	ll n;
	cin >> n;
	ll a[n];
	ll b[n+1];
	for(int i=0; i<n+1; i++)cin >> b[i];//the monstors
	for(int i=0; i<n; i++)cin >> a[i];//the hero
	ll ans = 0;
	for(int i=0; i<n; i++){
		ll suma = min(a[i],b[i]);
		a[i]-=suma;
		b[i]-=suma;
		ans+=suma;
		suma = min(a[i],b[i+1]);
		a[i]-=suma;
		b[i+1]-=suma;
		ans+=suma;
	}
	cout << ans << endl;
	return 0;
}
//