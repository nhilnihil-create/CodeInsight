#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif // ONLINE_JUDGE
	ll times=1;
	// cin>>times;
	while(times--)
	{
		ll n,val;
		cin>>n>>val;
		if(n*500>=val)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
}