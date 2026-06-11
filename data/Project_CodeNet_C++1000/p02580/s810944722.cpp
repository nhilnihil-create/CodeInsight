#include<bits/stdc++.h>
typedef  long long int ll;
typedef  long double ld;
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL) 
#define input(arr,n) for(ll i1=0;i1<n;i1++ )cin>>arr[i1]
#define mod 1000000007
#define F first
#define S second 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3")
//recursions\
#pragma comment(linker, "/stack:200000000")
//loops\
#pragma GCC optimize("unroll-loops")
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>//s.order_of_key(val) *s.find_by_order(ind)
using namespace std;
const int N = 1e6 + 5;
ll row[N], col[N], cnt[N], val[N];
int main()
{
	sync;
	ll h, w, m;
	cin >> h >> w >> m;
	vector<pair<ll,ll> > v;
	for(ll i = 1; i <= m ; i++)
	{
		ll x, y;
		cin >> x >> y;
		v.push_back({x, y});
		row[x]++;
		col[y]++;
	}
	ll maxm = *max_element(row, row + N), maxy = *max_element(col, col + N) ;
	set<ll> s;
	for(ll i = 0; i < m; i++)
	{
		if(row[v[i].F] == maxm)
			s.insert(v[i].F), val[v[i].F] = 1;
	}
	for(ll i = 0; i < m; i++)
		cnt[v[i].S] += val[v[i].F];
	ll sz =  s.size(), ans = maxm + maxy - 1;
	for(ll i = 0; i < m; i++)
		if(col[v[i].S] == maxy && cnt[v[i].S] != sz)
			ans = maxm + maxy;
	cout << ans;
}
	
	