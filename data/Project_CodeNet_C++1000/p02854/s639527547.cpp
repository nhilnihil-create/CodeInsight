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
const int M = 2e5+5;
ll a[M];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		a[i] += a[i-1];
	ll ans = 1e18;
	for(int i=1;i<n;i++)
	{
		ans = min(ans, abs(a[n]-2*a[i]));
	}
	cout<<ans<<"\n";
	return 0;
}