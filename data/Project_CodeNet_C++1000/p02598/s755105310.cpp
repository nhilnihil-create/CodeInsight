#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define PI 3.14159265358979323846
#define fi first
#define se second

ll mod = 1e9+7;

ll max(ll a, ll b ) {
	if(a>b)
		return a;
	else return b;
}
ll min(ll a, ll b ) {
	if(a<b)
		return a;
	else return b;
}

int main() {
	ll ttt;
	//cin>>ttt;
	ttt = 1;
	while(ttt--) {
		ll n,k; cin>>n>>k;
		ll a[n]; for(int i=0; i<n; i++) cin>>a[i];

		ll l = 1, h = 1e9 + 100;
		while(l<h) {
			ll mid = (l+h)/2;
			int flag = 0,totes = 0;
			
			for(int i=0; i<n; i++) {
				totes += (a[i]-1) / mid;
			}

			if(totes<=k) h = mid;
			else l = mid+1;
		}
		cout<<h;
 	}	
	return 0;
}