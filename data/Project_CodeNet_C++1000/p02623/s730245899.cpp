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

// index が条件を満たすかどうか
bool isOK(vl &a,vl &b, ll index, ll key) {
	ll tim = 0;
	if (index > a.size() + b.size()) {
		return false;
	}
	ll ai, bi;
	if (index <= a.size()) {
		rep(i, index) tim += a[i];
		ai = index - 1;
		bi = 0;
	}
	else {
		rep(i, a.size()) tim += a[i];
		rep(i, index - a.size()) tim += b[i];
		ai = a.size() - 1;
		bi = index - a.size();
	}
	if (tim <= key) return true;
	while (ai >= 0 && bi < b.size()) {
		tim -= a[ai--];
		tim += b[bi++];
		if (tim <= key) return true;
	}
	return false;
}

ll binary_search(vl &a,vl &b, ll key) {
	ll ng = a.size()+b.size()+1;
	ll ok = 0;

	while (abs(ok - ng) > 1) {
		ll mid = (ok + ng) / 2;

		if (isOK(a,b, mid, key)) ok = mid;
		else ng = mid;
	}
	return ok;
}

int main(void) {
	ll n, m, k;
	cin >> n >> m >> k;
	vl a(n), b(m);
	rep(i, n) cin >> a[i];
	rep(i, m) cin >> b[i];
	ll ans = binary_search(a, b, k);
	cout << ans << endl;
	return 0;
}
