#include <bits/stdc++.h>

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#define ll long long
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
#define en "\n"
#define FOR(i, j, n) for(int j = i; j < n; ++j)
#define forn(i, j, n) for(int j = i; j <= n; ++j)
#define nfor(i, j, n) for(int j = n; j >= i; --j)
#define sortv(vv) sort(vv.begin(), vv.end())
#define all(v) v.begin(), v.end()
#define ld long double
#define ull unsigned long long
#define pii pair <int, int>


using namespace std;
const ll maxn=1e3+100,inf=1e18,LOG=23,mod=1e9 + 7;
int block = 300, timer = 0;
const ld EPS = 1e-7;

#define bt(i) (1 << (i))
#define int ll

int n, have[1010][1010], uk[maxn], a[maxn][maxn], ans, res;

vector <pii> edge, nw;

main()
{
	cin >> n;
	forn(1, i, n)
	{
		forn(1, j, n - 1)
		{
			cin >> a[i][j];
		}
		uk[i] = 1;
		have[i][a[i][1]] = 1;
		if(have[a[i][1]][i] == 1)
		{
			edge.pb(mp(a[i][1], i));
		}
	}
	if(!edge.size())
	{
		cout << -1;
		return 0;
	}
	while(edge.size())
	{
//		cout << "NOW\n";
		FOR(0, i, edge.size())
		{
			int l = edge[i].f;
			int r = edge[i].s;
			res++;
//			cout << l << " " << r << endl;
			have[l][r] = 0;
			have[r][l] = 0;
			uk[l]++;
			uk[r]++;
			have[l][a[l][uk[l]]] = 1;
			if(have[a[l][uk[l]]][l])
			{
				nw.pb(mp(a[l][uk[l]], l));
			}
			have[r][a[r][uk[r]]] = 1;
			if(have[a[r][uk[r]]][r])
			{
				nw.pb(mp(a[r][uk[r]], r));
			}
		}
/*		forn(1, i, n)
		{
			forn(1, j, n)
			{
				cout << have[i][j] << " ";
			}
			cout << endl;
		}*/
		edge = nw;
		nw.clear();
		ans++;
	}
	if(res != n * (n - 1) / 2)
	{
		cout << -1;
	}
	else
	cout << ans;
}