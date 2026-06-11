#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define ll long long int
#define ld long long double
#define vi vector<int>
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define nl '\n'
#define mp make_pair
#define debug1(x) cout <<#x<<" "<<x<<'\n';
#define debug2(x,y) cout <<#x<<" "<<x <<" "<<#y<<" "<<y <<'\n';
#define debug3(x,y,z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<'\n';
#define fi first
#define se second
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define inf 1e18
const int mod = (int)1e9 + 7;
pair<ll, ll>s4[4] = {{ -1, 0}, {1, 0}, {0, -1}, {0, 1}};
pair<ll, ll>s8[8] = {{ -1, -1}, { -1, 0}, { -1, 1}, {0, -1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};

void judge() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

void solve() {
	int n;
	cin >> n;
	ll a[n + 1], b[n + 1], c[n];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	for (int i = 1; i < n; i++) {
		cin >> c[i];
	}
	int prev = -1;
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += b[a[i]];
		if (prev == a[i] - 1) {
			sum += c[prev];

		}
		prev = a[i];
	}
	cout << sum << nl;

}

signed main() {
	judge();
	boost;
	solve();
}
