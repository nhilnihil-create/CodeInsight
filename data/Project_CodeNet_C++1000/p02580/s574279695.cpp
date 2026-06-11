#include<bits/stdc++.h>
using namespace std;

#define Ff(i,a,b) for(i=a;i<b;i++)
#define Fb(i,a,b) for(i=a-1;i>=b;i--)
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define mp make_pair
#define PI 2*asin(1)
#define all(x) x.begin(),x.end()
#define trav(x) for(auto& i:x)
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
// #define in(a,x) scanf("%a",&x)
// #define out(a,x) printf("%a",x)

// #define int long long

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<long long> vll;
typedef map<int, int> mi;
typedef map<long long, long long> mll;
typedef unordered_map<int, int> umi;
typedef unordered_map<long long, long long> umll;
typedef set<int> si;
typedef set<long long> sll;
typedef unordered_set<int> usi;
typedef unordered_set<long long> usll;

const ll N = 1e9 + 7;

// #define int long long

void sub() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);
#endif
}

bool comp(pair<int, int>a, pair<int, int>b) {
	return (a.ss > b.ss);
}

void solve() {
	int n, m;
	cin >> n >> m;
	unordered_map<int, int> x, y;
	int k, i;
	cin >> k;
	int g, h;
	// int p[n + 1][m + 1] = {0};
	set<pair<int, int>>s;
	Ff(i, 0, k) {
		cin >> g >> h;
		// p[g][h] = 1;
		s.insert(mp(g, h));
		x[g]++;
		y[h]++;
	}
	int ma = -1, mb = -1;
	trav(x) {
		if (i.ss > ma)
			ma = i.ss;
	}
	trav(y) {
		if (i.ss > mb)
			mb = i.ss;
	}
	vector<int>a, b;
	for (auto it = x.begin(); it != x.end(); it++)
		if (it->ss == ma)a.pb(it->ff);
	x.clear();
	for (auto it = y.begin(); it != y.end(); it++)
		if (it->ss == mb)b.pb(it->ff);
	y.clear();
	// sort(all(a), comp);
	// sort(all(b), comp);
	auto ia = a.begin();
	auto ib = b.begin();
	// cout << ma << ' ' << mb << ' ';
	int mx = ma + mb;
	// ia++;ib++;
	while (ia != a.end()) {
		ib = b.begin();
		while (ib != b.end()) {
			if (s.find(mp(*ia, *ib)) == s.end()) {cout << mx << endl; return;}
			ib++;
		}
		ia++;
	}

	cout << mx - 1 << endl;


}

int32_t main() {
	FIO
	sub();
	int t = 1;
	// cin >> t;
	while (t--)
		solve();
	return 0;
}


