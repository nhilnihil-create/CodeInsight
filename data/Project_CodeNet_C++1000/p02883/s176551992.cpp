#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repn(i, n) for (int i = 0; i <= (int)(n); i++)
#define srep(i, l, n) for (int i = l; i < (int)(n); i++)
#define srepn(i, l, n) for (int i = l; i <= (int)(n); i++)
#define pb push_back 
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int MOD = 1000000007;
const ll INF = 1e18;
#define PI 3.14159265369;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};





int main(){
	int n; ll k;
	cin >> n >> k;
	vector<ll> a(n), f(n);
	rep(i,n) cin >> a[i];
	rep(i,n) cin >> f[i];
	sort(a.begin(), a.end());
	sort(f.rbegin(), f.rend());

	auto ok = [&](ll x) {
		ll cost = 0;
		rep(i,n) {
			cost += max(0LL, a[i]-x/f[i]);
		}
		return cost <= k;
	};

	ll l = -1, r = INF;
	while(r-l>1) {
		ll mid = (r+l)/2;
		if(ok(mid)) r = mid;
		else l = mid;
	}

	cout << r << endl;
}