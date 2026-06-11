#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//Write From this Line

// Binary Indexed Tree (Fenwick Tree)
// https://youtu.be/lyHk98daDJo?t=7960
template<typename T>
struct BIT {
	int n;
	vector<T> d;
	BIT(int n=0):n(n),d(n+1) {}
	void add(int i, T x=1) {
		for (i++; i <= n; i += i&-i) {
			d[i] += x;
		}
	}
	T sum(int i) {
		T x = 0;
		for (i++; i; i -= i&-i) {
			x += d[i];
		}
		return x;
	}
	T sum(int l, int r) {
		return sum(r-1) - sum(l-1);
	}
};
int main()
{
	int n, d, a;
	cin >> n >> d >> a;
	vector<P> p(n);
	rep(i,n) cin >> p[i].first >> p[i].second;
	sort(p.begin(),p.end());

	BIT<ll> bit(n+1);
	ll ans = 0;
	rep(i,n) {
		ll x = p[i].first;
		ll h = p[i].second;
		h -= bit.sum(i);
		if (h <= 0) continue;
		ll num = (h+a-1)/a;
		ans += num;
		ll damage = num*a;
		bit.add(i,damage);
		int rx = min(x+d*2, 1001001001ll);
		int j = upper_bound(p.begin(),p.end(), P(rx+1,-1)) - p.begin();
		bit.add(j, -damage);
	}
	cout << ans << endl;
}
