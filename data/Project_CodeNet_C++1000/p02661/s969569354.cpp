#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define rep(i, l, r) for (ll i = (l); i < (r); ++i)
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define pli pair<ll, ll> 
#define pdd pair<ld, ld> 
#define pb push_back
#define reset(x,v) memset(x,v,sizeof(x))
#define mod 1000000007
using namespace std;

int main(){
	FASTIO
	int n;
	cin >> n;
	ll a[n], b[n];
	rep(i, 0, n){
		cin >> a[i] >> b[i];
	}
	sort(a, a + n);
	sort(b, b + n);
	if(n % 2){
		cout << b[n/2] - a[n/2] + 1;
	} else {
		cout << (b[(n-1)/2] + b[n/2] - a[(n-1)/2] - a[n/2]) + 1;
	}
    return 0;
}