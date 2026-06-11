#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll n,k;
	cin >> n >> k;
	vector<ll> A(n),F(n);
	for(int i = 0;i<n;i++)cin >> A[i];
	for(int i = 0;i<n;i++)cin >> F[i];

	sort(A.begin(),A.end());
	sort(F.rbegin(),F.rend());

	ll sum = 0;
	for(int i = 0;i<n;i++)sum += A[i];
	if(sum <= k)
	{cout << 0 << endl; return 0;}

	ll l = 0,r = 1e18;
	while(1)
	{
		ll m = (r+l)/2;
		ll now = 0;
		for(int i = 0;i<n;i++)if(F[i]*A[i]>m)now += A[i] - m/F[i];

		if(now<=k)r = m;
		else l = m;
		if(r-l<2)break;
	}
	cout << r << endl;
	
}
