/////////////////////////////////TEST CASES////////////////////////////////////
/*
*/
/////////////////////////////////////CODE//////////////////////////////////////		
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for (ll i = a ; i > b ; i--)
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define PI 3.14159265
typedef long long ll;
#define vl vector<ll> 
#define IN(inp) ll inp;cin>>inp;
#define pb push_back
#define all(a) a.begin(),a.end()
#define FR(i,a) for(auto i:a)
#define rvl(a,n) vl a;FOR(i,0,n){IN(in); a.pb(in);}
#define what(A) cout<<#A<<" is "<<A<<endl;
ll MAX = 100000000000;
ll MOD = 998244353;
ll arr[200010];
ll find(ll u)
{
	while (arr[u] > 0)
	{
		u = arr[u];
	}
	return u;
}
void solve()
{
	IN(n)IN(q);
	memset(arr, -1, sizeof(arr));
	while (q--)
	{
		IN(t)IN(u)IN(v);
		if (t == 0)
		{
			if (find(u) != find(v))
			{
				arr[find(u)] = find(v);
			}
		}
		else
		{
			if (find(u) != find(v))
			{
				cout << 0 << endl;
			}
			else
			{
				cout << 1 << endl;
			}
		}
	}
}
int main()
{
	fastio
		//freopen("input.txt", "rt", stdin);
		//freopen("output.txt", "wt", stdout);
		ll test = 1;
	//cin >> test;
	while (test--)
	{
		solve();
	}
}