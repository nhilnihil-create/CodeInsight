#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <math.h>
#include <string>
#include <numeric>
#include <queue>
#include <cstdio>
#include <cstring>
#define ll long long
#define rep(i,n) for(ll i=0;i<n;++i)
#define rep1(i,n) for(ll i=1;i<n;++i)
#define mrep(i,n) for(ll i=n;i>=0;--i)
#define all(a) (a).begin(),(a).end()
#define vl vector<ll>
#define vvl vector<vector<ll> >
#define vb vector<bool>
#define vvb vector<vector<bool> >
#define pl pair<ll,ll>
#define inf 1001001001001001000
//#define mod 1000000007
#define mod 998244353
#define pi 3.1415926535
using namespace std;
struct __INIT {
	__INIT() {
		cin.tie(0);
		ios::sync_with_stdio(false);
		cout << fixed << setprecision(15);
	}
}__init;


int main(void) {
	ll n, d;
	cin >> n >> d;
	vvl x(n, vl(d));
	rep(i, n) rep(j, d) {
		cin >> x[i][j];
	}
	ll ans = 0;
	rep(i, n) for (ll j = i + 1; j < n; j++) {
		double d1 = 0;
		rep(k, d) d1 += (x[i][k]-x[j][k])*(x[i][k]-x[j][k]);
		d1 = sqrt(d1);
		if (d1 == (ll)d1) ans++;
	}
	cout << ans << endl;
	return 0;
}
