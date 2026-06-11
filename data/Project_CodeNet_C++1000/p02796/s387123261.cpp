#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;   
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
#define ld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define sz(a) (ll)(a.size())
const int M = 1e5+5;
int x[M],l[M];
int main()
{
	int n;
	cin>>n;
	vector<pair<int,int>> vec;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>l[i];
		vec.pb({x[i]+l[i],i});
	}
	sort(all(vec));
	int ans = 0;
	int pre = -1e9;
	for(auto u:vec)
	{
		int z = u.ss;
		if(x[z]-l[z]>=pre)
		{
			ans++;
			pre = u.ff;
		}
	}
	cout<<ans<<"\n";
	return 0;
}