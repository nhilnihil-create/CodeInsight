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
#define pii pair <int, int>


using namespace std;
const ll maxn=2e5+100,inf=1e18,LOG=23,mod=1e9+7;
int block = 300, timer = 0;
const ld EPS = 1e-7;

#define bt(i) (1 << (i))
#define int ll

int n, k, c, a[maxn], dpl[maxn], dpr[maxn], suff[maxn], pref[maxn], can[maxn];
multiset <int> st;

main()
{
	cin >> n >> k >> c;
	forn(1, i, n)
	{
		char ch;
		cin >> ch;
		if(ch == 'o')
		{
			a[i] = 1;
		}
	}
	forn(1, i, n)
	{
		if(i - c - 1 < 0) dpl[i] = 1;
		else
			dpl[i] = pref[i - c - 1] + 1;
		if(a[i] == 0)
		{
			dpl[i] = 0;
		}
		pref[i] = max(pref[i - 1], dpl[i]);
	}
	nfor(1, i, n)
	{
		dpr[i] = suff[i + c + 1] + 1;
		if(a[i] == 0)
		{
			dpr[i] = 0;
		}
		suff[i] = max(suff[i + 1], dpr[i]);
	}
	forn(1, i, n)
	{
		if(i - 1 > 0 && a[i - 1] == 1)
		{
			st.insert(dpl[i - 1] + suff[i + c]);
		}
		if(i - c - 1 > 0 && a[i - c - 1] == 1)
		{
			st.erase(st.find(dpl[i - c - 1] + suff[i]));
		}
		if(st.size() && *st.rbegin() >= k)
		{
			can[i] = 1;
		}
	}
	forn(1, i, n)
	{
		if(i - c - 1 >= 0 && pref[i - c - 1] + suff[i + 1] >= k)
		{
			can[i] = 1;
		}
		if(i - c - 1 < 0 && suff[i + 1] >= k)
		{
			can[i] = 1;
		}
	}
	forn(1, i, n)
	{
		if(!can[i] && a[i] == 1)
		{
			cout << i << endl;
		}
	}
}