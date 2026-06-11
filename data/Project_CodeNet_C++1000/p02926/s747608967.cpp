#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define ld long double
#define vii vector<ii>
#define vll vector<ll>
#define maxn 111

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

ii a[maxn];
ii op = {0, 10000000};

int cross(ii a, ii b) {
	return a.fi*b.se - a.se*b.fi;
}

bool cmp (ii x, ii y) {
	return atan2(x.second, x.first) < atan2(y.second, y.first);
}

int32_t main(){
	int n,x,y;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		a[i] = {y, x};
	}
	sort(a,a+n, cmp);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int j = i, left = n, dx = 0, dy = 0;
		while (left--) {
			dx += a[j].fi;
			dy += a[j].se;
			ans = max(ans, dx*dx + dy*dy);
			j = (j+1) % n;
		}
	}
	cout << fixed << setprecision(40) << sqrt(ans) << '\n';
 	return 0;
}

