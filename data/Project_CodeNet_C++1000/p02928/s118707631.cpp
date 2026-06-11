#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;

int main(){
	ll n,k;cin>>n>>k;
	vector<ll> a(n);
	vector<ll> b;
	for(int i = 0; i < n; i++) {
		cin>>a[i];
	}
	
	vector<ll> x(n,0);
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if (a[i] > a[j]){
				x[i]++;
			}
		}
	}
	vector<ll> y(n,0);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if (a[i] > a[j]){
				y[i]++;
			}
		}
	}
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		if ( k % 2 == 0){
			ll tmp = k / 2;
			ans += (((k * x[i]) % mod) + ((y[i] * ((tmp * (k - 1) % mod))) % mod) % mod);
		}
		else{
			ll tmp = (k - 1) / 2;
			ans += (((k * x[i]) % mod) + ((y[i] * ((k * tmp % mod))) % mod) % mod);
		}
		
		ans %= mod;
	}

	cout << ans << endl;
	return 0;
}