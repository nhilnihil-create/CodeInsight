#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,ans=0;
	cin>>n;
	ll ar[n];
	for (int i=0;i<n;i++)
		cin>>ar[i];
	sort(ar,ar+n);
	for (int i=1,j=n-1;i<n;i++)
	{
		if (!(i%2))j--;
		ans+=ar[j];
	}
	cout<<ans<<"\n";
}