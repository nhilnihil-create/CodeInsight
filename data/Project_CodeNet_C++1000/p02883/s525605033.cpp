#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,k;
	cin>>n>>k;
	vector<ll> a(n),f(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		cin>>f[i];
	
	sort(a.begin(),a.end());
	sort(f.rbegin(),f.rend());
	// for(auto t: a)
	// 	cout<<t<<" ";
	// cout<<endl;
	// for(auto t:f)
	// 	cout<<t<<" ";
	// cout<<endl;
	ll low=0,high=1e18;
	while(low<high)
	{
		ll mid=(low+high)>>1;
		ll cnt=0;
		for(int i=0;i<n;i++)
		{
			if(mid<a[i]*f[i])
				cnt+=a[i]-mid/f[i];
		}
		// cout<<mid<<" "<<cnt<<endl;
		if(cnt<=k)
			high=mid;
		else
			low=mid+1;
	}
	cout<<low<<endl;
}
