#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{

	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	// #ifndef ONLINE_JUDGE
 //    freopen("input.txt" , "r" , stdin);
	// freopen("output.txt" , "w" , stdout);
	// #endif

	ll n,k,s,z;
	cin>>n>>k>>s;
	for(ll i=1;i<=k;i++)
		cout<<s<<" ";
	if(s==1000000000)
		z=1;
	else
		z=s+1;

	for(ll i=k+1;i<=n;i++)
	{
		cout<<z<<" ";
	}

	
	
}
