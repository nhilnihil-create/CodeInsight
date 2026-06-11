#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

// find_by_order(k) returns the iterator to the kth largest element (start from 0)
// order_of_key(k) returns the number of elements in the set which are strictly less than the value k

using namespace std;
using namespace __gnu_pbds;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define rightmostbit(x) __builtin_ffsll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         cout << fixed; cout << setprecision(x); cout << y;
#define pi              3.141592653589793238
#define mk(a,n)         int n;cin>>n;vi a(n);for(int i=0;i<n;i++) cin>>a[i]
#define w(x)            int x; cin>>x; while(x--)
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

int dx[] = { -1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int dx2[] = { -1 , -1 , -1, 0 , 0 , 1 , 1 , 1};
int dy2[] = { -1 , 0 , 1 , -1, 1 , -1, 0, 1};

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void g_b()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
}
// 1, 1, 2, 5, 14, 42, 132, 429, 1430, CATALAN NUMBER
int m[1000001];
int32_t main()
{
	g_b();
	int tot;
	mk(a, n);
	string ans = "not coprime";
	for (auto x : a) m[x]++;
	bool f = 0;
	for (int i = 2; i <= 1000000; i++)
	{
		int c = 0;
		for (int j = i; j <= 1000000; j += i) {c += m[j];}
		if (c > 1) {f = 1; break;}
	}
	if (!f)
	{
		cout << "pairwise coprime";
		return 0;
	}
	int res = a[0];
	for (int i = 1; i < n; ++i)
	{
		res = __gcd(res, a[i]);
	}
	if (res == 1) ans = "setwise coprime";
	cout << ans;
	return 0;
}
