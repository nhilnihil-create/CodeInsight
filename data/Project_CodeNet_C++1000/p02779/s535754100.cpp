#include"bits/stdc++.h"
using namespace std;

#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define nl "\n"
#define sp " "
#define int long long

int32_t main()
{
	FastIO;
	int n;
	bool ok=true;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n-1;i++)
	{
		if(a[i]==a[i+1])
		{
			ok=false;
			break;
		}
	}
	if(ok) cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}
