#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define endl "\n"

int power(int a,int b,int m=mod)
{
	if(b==0)	return 1;
	if(b==1)	return a;
	int res=power(a,b/2,m);
	res=(res*res)%m;
	if(b&1)	res=(res*a)%m;
	return res;
}

int modinv(int a){ return power(a,mod-2);}

void solve()
{
	int n,ans=2,i;
	cin>>n;
	if(n==2){	cout<<"1"<<endl;return;}
	int m=n-1;
	for(i=2;i*i<=n;i++)
	{
		if(m%i==0)
		{
			ans++;
			ans+=1-(i*i==m);
		}
		if(n%i==0)
		{
			int x=n;
			while(x%i==0)
				x/=i;
			if(x%i==1)	ans++;
		}
	}
	cout<<ans<<endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t=1;//cin>>t;
	while(t--)	solve();
	return 0;
}