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
	int n,ans = 0;
	cin>>n;
	for(int i = 1; i<n; i++)
	{
		int h = n-i;
		for(int j = 1; j*j<=h; j++)
			if(h%j==0)
			{
				ans++;
				if(j*j!=h) ans++;
			}
	}
	cout<<ans<<'\n';
	return 0;
}