#include<bits/stdc++.h>
const int M=1e9+7;// M=1e9+7;//M=300000;//
const int N=2e6+5;
typedef long long int ll;
using namespace std;
 
ll cnt(0),sum(0),n,m,x,y,t,i,j,temp,k,ans(0),mn(M),mx(-9e9);

ll pow_mod(ll a,ll b) //to calculate the power
{
	ll M=2e9+7;
	if(b==0)
	{
		return 1;
	}
	if(b==1)
	{
		return a%M;
	}
	ll res=1;
	while(b)
	{
		if(b%2==1)
		{
			res=(res*a)%M;
		}
		a=(a*a)%M;
		b/=2;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(i=-200;i<200;i++)
	{
		for(j=-200;j<200;j++)
		{
			x=pow_mod(i,5);
			y=pow_mod(j,5);
			if(x-y==n)
			{
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	
}