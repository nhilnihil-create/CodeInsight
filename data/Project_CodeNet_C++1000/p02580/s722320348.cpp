#include <bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mii map<int,int>
#define mll map<ll,ll>
#define all(x) (x).begin(),(x).end()
#define S(x) (int)(x).size()
#define L(x) (int)(x).length()
#define ld long double
#define mem(x,y) memset(x,y,sizeof x)

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int , null_type , less<int> , rb_tree_tag , tree_order_statistics_node_update> ordered_set;

const int mod = 1e9+7;
const ll infl = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
/*
 * Be careful of overflow
 * Array bounds
 * Assert a!=0 when performing x/a
 * Check base condition for recursion
 * Iterator -> O(1), Element -> O(log n) while using erase
 * 1LL<<x when x>32
 * Be sure of what you are going to code (exception dp)
 * Don't try fancy tricks during contest
 * You can always make a bad round to a good enough round
 */ 

int h[300009],w[300009];
vector<pii> tar;
vector<pii> hh,ww;

set<int> hhh,www;

void solve()
{
	int H,W;
	cin>>H>>W;
	int m,i;
	cin>>m;
	for(i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		h[a]++;
		w[b]++;
		tar.pb({a,b});
	}
	
	for(i=1;i<=H;i++)
	{
		if(h[i]) hh.pb({h[i],i});
	}
	
	sort(all(hh),greater<pii>());
	
	for(i=1;i<=W;i++)
	{
		if(w[i]) ww.pb({w[i],i});
	}
	sort(all(ww),greater<pii>());
	
	int ans = hh[0].fi + ww[0].fi;
	
	i=0;
	while(i<S(hh) && hh[i].fi == hh[0].fi)
	{
		hhh.insert(hh[i].se);
		i++;
	}
	
	i=0;
	while(i< S(ww) && ww[i].fi == ww[0].fi)
	{
		www.insert(ww[i].se);
		i++;
	}
	int cnt=0;
	for(auto u:tar)
	{
		if(hhh.count(u.fi) && www.count(u.se))
		{
			cnt++;
		}
	}
	ll tot = 1LL * S(hhh) * S(www);
	if(tot == cnt ) ans--;
	cout<<ans<<'\n';
}

int main()
{
	IOS
	int t=1;
	//cin>>t;
	while(t--)
	{
		solve();
	}
}
