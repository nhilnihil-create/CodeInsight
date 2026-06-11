#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
#define MOD 1000000007

ll mod_inv(ll a)
{
	ll ret=1;
	ll ks=a;
	ll left=MOD-2;
	while(left>0)
	{
		if(left%2==1)
		{
			ret=ret*ks%MOD;
		}
		ks=ks*ks%MOD;
		left/=2;
	}
	return ret;
}

int main()
{
	int n,k;cin>>n>>k;
	vector<int> a(n);
	int i,j;
	rep(i,n)cin>>a[i];
	ll ans0=0;
	ll ans1=0;
	rep(i,n)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])ans0++;
		}
	}
	rep(i,n)
	{
		rep(j,n)
		{
			if(a[i]>a[j])ans1++;
		}
	}
	ans0=(ans0*k)%MOD;
	ans1=(ans1*k)%MOD;
	ans1=(ans1*(k-1))%MOD;
	ans1=(ans1*mod_inv(2))%MOD;
	cout<<(ans0+ans1)%MOD<<endl;
}
