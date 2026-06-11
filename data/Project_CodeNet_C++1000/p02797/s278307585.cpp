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
int main()
{
	int n,k,s;
	cin>>n>>k>>s;
	int z = 1e9;
	if(s!=z)
	{
		for(int i=1;i<=k;i++)
			cout<<s<<" ";
		for(int i=1;i<=n-k;i++)
			cout<<z<<" ";
		cout<<"\n";
	}
	else
	{
		for(int i=1;i<=k;i++)
			cout<<z<<" ";
		for(int i=1;i<=n-k;i++)
			cout<<"1 ";
		cout<<"\n";
	}
	return 0;
}