#include <bits/stdc++.h>
#include <random>

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

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
const ll maxn=2e5+100,inf=1e9,LOG=23,mod=1e9+7;
ll block = 300, timer = 0;
const ld EPS = 1e-7;

#define bt(i) (1 << (i))
#define int ll
#define y1 yy
#define pii pair <int, int>

int n, pu[4*maxn], t[4*maxn], ans;
vector <int> edge[maxn];

void upd(int v, int tl, int tr, int l, int r, int val)
{
	if(l <= tl && tr <= r)
	{
		t[v] += val * (tr - tl + 1);
		pu[v] += val;
		return;
	}
	if(l > tr || r < tl) return;
	int mid = (tl + tr) / 2;
	t[v * 2] += pu[v] * (mid - tl + 1);
	pu[v * 2] += pu[v];
	t[1 + v * 2] += pu[v] * (tr - mid);
	pu[1 + v * 2] += pu[v];
	pu[v] = 0;
	upd(v * 2, tl, (tl + tr) / 2, l, r, val);
	upd(v * 2 + 1, (tl + tr) / 2 + 1, tr, l, r, val);
	t[v] = t[v * 2] + t[v * 2 + 1];
}

main()
{
	IOS
	cin >> n;
	forn(1, i, n - 1)
	{
		int l, r;
		cin >> l >> r;
		if(l > r) swap(l, r);
		edge[r].pb(l);
	}
	forn(1, i, n)
	{
		edge[i].pb(0);
		sort(all(edge[i]));
		reverse(all(edge[i]));
		int cur = 1;
		int last = i;
		for(auto to : edge[i])
		{
			upd(1, 1, n, to + 1, last, cur);
//			cout << to + 1 << " " << last << " " << cur << " " << t[1] << endl;
			cur--;
			last = to;
		}
		ans += t[1];
	}
	cout << ans;
}