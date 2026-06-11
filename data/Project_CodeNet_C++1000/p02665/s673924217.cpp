#include <bits/stdc++.h>
using namespace std;
 
#define vi vector<int>
#define ll long long
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vll>
#define MOD 1000000007
#define endL << '\n'
#define ii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define endL << '\n'
#define vii vector<ii>
#define pb push_back

/*
ll powmod(ll x, ll y, ll mod){
	ll res = 1;
	while (y > 0){
		if (y%2) res = (res*x) % mod;
		x = (x*x) % mod;
		y /= 2;
	}
	return res;
}
*/

/*const int N = 1000000;
int lp[N+1];
vector<ll> pr;

void sieve(){
	for (int i=2; i<=N; ++i) {
	    if (lp[i] == 0) {
	        lp[i] = i;
	        pr.push_back (i);
	    }
	    for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
	        lp[i * pr[j]] = pr[j];
	}
}*/

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1; //cin >> t;
	while(t--){
		int n; cin >> n; n++;
		vll a(n); for (int i = 0; i < n; i++) cin >> a[i];
		vll suff(n); 
		for (int i = n-1; i >= 0; i--){
			suff[i] = (i == n-1) ? a[i] : a[i] + suff[i+1];
		}
		ll ans = 0ll, up = 1ll;
		for (int i = 0; i < n; i++){
			up = min(up, suff[i]);
			if (a[i] > up) {cout << -1; return 0;}
			ans += up;
			up = (up - a[i]) * 2;
		}
		cout << ans;
	}
}