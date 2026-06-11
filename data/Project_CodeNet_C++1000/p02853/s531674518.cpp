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
	int x,y;
	cin>>x>>y;
	int res = 0;
	int z = 1e5;
	if(x<=3)
		res += (4-x)*(z);
	if(y<=3)
		res += (4-y)*(z);
	if(x==1 && y==1)
		res += 4*z;
	cout<<res<<"\n";
	return 0;
}