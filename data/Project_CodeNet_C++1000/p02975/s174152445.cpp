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

	ll n,x=0;
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		ll a;
		cin>>a;
		x=x^a;
	}
	if(!x)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;


	
	
}
