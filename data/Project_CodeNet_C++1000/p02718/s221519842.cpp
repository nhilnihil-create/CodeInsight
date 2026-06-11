#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
	int n,m;
	cin>>n>>m;
	int a[n];
	int cn = 0;
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		cin>>a[i];
		sum += a[i];
	}
	double b = sum/(double)(4*m);
	for (int i = 0; i < n; ++i)
	{
		/* code */
		if(a[i]>=b)
			cn++;
	}
	if(cn>=m)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
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