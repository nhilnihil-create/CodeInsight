#include<bits/stdc++.h>
using namespace std;
#define vb __int128
#define ll long long
#define ld long double
#define full(a) a.begin(),a.end()
#define stoink stack<ll>
#define vec vector <ll>
#define vg vector<vector<ll> >
#define vgw vector<vector<pair<ll,ll> >
#define pa pair<ll,ll>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define pre 0.00000000000000000001
#define inf 1000000000000
#define mod 998244353
bool comp(pa a,pa b) {
	if(a.ff  == b.ff)
		return a.ss < b.ss;
	return a.ff < b.ss;
}
int main()
{	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin >> n;
	vec a(n),b(n);
	ll i;
	for(i = 0 ; i < n ; i++) {
		cin >> a[i] >> b[i];
	}
	sort(full(a));
	sort(full(b));
	if(n & 1) {
		ll ind = n / 2;
		ll ans = b[ind] - a[ind] + 1;
		cout << ans ;	
	}
	else {
		ll ind1 = n / 2;
		ind1--;
		ll ind2 = ind1 + 1;
		ld med1 = ((ld)a[ind1] + (ld)a[ind2]) / 2;
		ld med2 = ((ld)b[ind1] + (ld)b[ind2]) / 2;
		ld ans = (med2 - med1) / 0.5;
		ans++;
		ll anss = (ll)ans;
		cout << anss ;	
	}
	return 0;
}