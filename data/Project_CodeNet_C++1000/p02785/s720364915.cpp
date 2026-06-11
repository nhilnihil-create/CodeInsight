#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define u(x, a, b) for(ll x = a; x < b; x++)
#define d(x, a, b) for(ll x = a; x > b; x--)

typedef long long ll;
typedef long double ld;

#define MAXI 100010
#define MOD 1000000007

int main(){
	ll n, k;
	cin >> n >> k;
	
	
	ll h[n];
	ll tot = 0;
	
	u(one, 0, n){cin >> h[one]; tot+=h[one];}
	sort(h, h+n);
	
	d(one, n-1, max((ll)-1, n-k-1)){tot-=h[one];}
	
	cout << tot;
}
