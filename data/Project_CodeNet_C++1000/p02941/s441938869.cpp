#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
using namespace std;

typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
typedef long double ld;
const ll mod = 1000000007;
const ll INF = mod * mod;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<int, int> P;
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
typedef vector<int> vec;
typedef vector<string> svec;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define pb push_back
//#define int long long

void solve() {
	int n; cin >> n;
	vector<ll> a(n), b(n);
	priority_queue<pair<ll, int>> pque;
	rep(i, n) {
		cin >> a[i];
	}
	rep(i, n) {
		cin >> b[i];
		if(b[i] != a[i]) pque.push(make_pair(b[i], i));
	}
	ll cnt = 0;
	while(pque.size()) {
		pair<ll, int> p = pque.top(); pque.pop();
		int pos = p.second;
		ll minus = b[(pos - 1 + n) % n] + b[(pos + 1) % n];
		ll c = (b[pos] - a[pos]) / minus;
		if(c == 0) {
			cout << -1 << endl;
			return;
		}
		b[pos] -= minus * c; //b[pos] %= minus;
		cnt += c;
		if(b[pos] > a[pos]) pque.push(make_pair(b[pos], pos));
	}
	cout << cnt << endl;
}
 
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init();
	solve();
	//cout << "finish" << endl;
    return 0;
}