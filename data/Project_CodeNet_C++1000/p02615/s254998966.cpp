#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll a[200100];
ll ans;
bool cmp(ll a,ll b)
{
	return a>b;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n,cmp);
	ans=a[1];
	int p=1;
	for(int i=2;i<=n;i++)
	{
		p+=2;
		if(p<n)  ans+=a[i]*2;
		else      
		{
			if(p==n)   ans+=a[i];
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}