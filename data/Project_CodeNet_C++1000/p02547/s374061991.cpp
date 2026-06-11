#include<bits/stdc++.h>
#define ll long long int
#define ar array
#define pb push_back
#define input(arr,n) for(int i = 0; i<n; i++) cin>>arr[i]
const int mod = 1e9+7;
ll power(ll a,ll b){ll r=1;for(;b;b>>=1){if(b&1)r=r*a%mod;a=a*a%mod;}return r;}
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	vector<ar<int,2>> v;
	for(int i = 0, j,k ; i<n; i++)
	{
		cin>>j>>k;
		v.pb({j,k});
	}
	bool ans = false;
	for(int i = 0; i<n-2; i++)
	{
		if(v[i][0]==v[i][1])
		{
			if(i+1<n)
			{
				if(v[i+1][0]==v[i+1][1])
				{
					if(i+2<n)
					{
						if(v[i+2][0]==v[i+2][1]) ans = 1;
					}
				}
			}
		}
	}
	if(ans) cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}