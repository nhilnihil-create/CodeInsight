
#include <bits/stdc++.h>
using namespace std;


#define M 1000000007
#define pb push_back
#define mp make_pair
#define s second
#define f first
#define mod 998244353
#define sz(v) (int)(v).size()

#define pii pair<int, int>
#define vi vector<int>
#define ll long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0)

ll add(ll a,ll b)
{
	a%=M;
	b%=M;
	ll p = (a+b)%M;
	return (p+M)%M;
}

ll mul(ll a,ll b)
{
	a%=M;
	b%=M;
	ll p = (a*b)%M;
	return (p+M)%M;
}


int main()
{
	fastio;
	ll i,j,n,k,c,pre[200010]={0},suf[200010]={0};
	cin>>n>>k>>c;
	string str;
	cin>>str;
	str = " "+str;
	for(i=1;i<=n;i++)
	{
		pre[i]=1;
		if((str[i]!='x')&&(i>c))
			pre[i]=max(pre[i],pre[i-c-1]+1);
		pre[i]=max(pre[i],pre[i-1]);
	}
	for(i=n;i>0;i--)
	{
		suf[i]=1;
		if((str[i]!='x')&&(i+c+1<=n+1))
			suf[i]=max(suf[i],suf[i+c+1]+1);
		suf[i]=max(suf[i],suf[i+1]);	
	}
	if(c==0)
	{
		ll cnt=0;
		for(i=1;i<=n;i++)
		{
			if(str[i]=='o')
				cnt++;
		}
		if(cnt==k)
		{
			for(i=1;i<=n;i++)
			{
				if(str[i]=='o')
					cout<<i<<endl;
			}
		}
		return 0;
	}
	// for(i=1;i<=n;i++)
	// 	cout<<pre[i]<<" ";
	// cout<<endl;
	// for(i=1;i<=n;i++)
	// 	cout<<suf[i]<<" ";
	// cout<<endl;
	ll sum[200010]={0};
	j=0;
	for(i=1;i<=n;)
	{
		if(j!=n+1)		
			j++;
		else
			i++;
		if(j-i+1>c)
			i++;
		ll val = pre[i-1]+suf[j+1];
		// if(i==1)
		// 	cout<<val<<endl;
		if(val>=k)
		{
			sum[i]++;
			sum[j+1]--;
		}
	}
	ll cur=0;
	for(i=1;i<=n;i++)
	{
		cur+=sum[i];
		if(cur==0)
			cout<<i<<endl;
	}
	// cout<<endl;
    return 0;
}


