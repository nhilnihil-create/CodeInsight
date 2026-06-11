
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
	ll n,i,sq;
	cin>>n;
	sq=sqrt(n);
	ll ans=1;
	for(i=2;i<=sq;i++)
	{
		ll fl=0,pre=i;
		while(pre*i<=n)
		{
			fl += ((n-pre)%(pre*i)==0);
			fl += (n==pre*i);
			pre *= i;
		}
		ans += (fl>0);
		// cout<<fl<<" ";
	}
	// cout<<ans<<endl;
	sq=sqrt(n-1);
	for(i=2;i<=sq;i++)
	{
		if((n-1)%i==0)
		{
			ans++;
			if(n-1!=i*i)
				ans++;
		}
	}
	ans++;
	if(n==2)
		ans=1;
	cout<<ans<<endl;
    return 0;
}



