#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
	int x,y,z;
	cin>>x>>y>>z;
	swap(x,y);
	swap(x,z);
	cout<<x<<" "<<y<<" "<<z<<endl;
}

int main()
{
	ll t = 1;
	// cin>>t;
	while(t--)
	{
		solve();
	}
}