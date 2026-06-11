#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0)
#define endl "\n";
#define pb push_back
#define ff first
#define ss second
#define all(a) a.begin(),a.end()
#define int long long
const int MOD=1e9+7;
const int N=3e5+10;
int a[N];
 
int pow(int a, int b, int m)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}
 
int modinv(int k)
{
	return pow(k, MOD-2, MOD);
}
int ans[N];
int32_t main()
{
	IOS;
	int n,k;
	cin>>n>>k;
	for(int i=k;i>=1;i--)
	{
		int ans1=pow(k/i,n,MOD);
		for(int j=2*i;j<=k;j+=i)
		{
			ans1-=ans[j];
			ans1+=MOD;
			ans1%=MOD;
		}
		ans[i]=ans1;
	}
	int sum=0;
	for(int i=1;i<=k;i++)
	{
		sum+=(ans[i]*i)%MOD;
		sum%=MOD;
	}
	cout<<sum<<endl;
	
	
}