#include<bits/stdc++.h>
using namespace std;
#define ff              first
#define ss              second
#define f(i,n)          for(int i=0;i<n;i++)
#define int             long long
#define pb              push_back
#define mp              make_pair
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
void g_b()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
}
int32_t main()
{
	g_b();
	int n; cin >> n;
	int x = 102;
	vi ans(10005);
	for (int i = 1; i <= x; i++)
	{
		for (int j = 1; j <= x; j++)
		{
			for (int k = 1; k <= x; k++)
			{
				int p = i * i + j * j + k * k + i * j + j * k + k * i;
				if ( p < 10005) ans[p] += 1;
			}
		}
	}

	for (int i = 1; i <= n; i++)
		cout << ans	[i] << endl;
	return 0;

}

