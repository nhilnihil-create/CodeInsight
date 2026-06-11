#include <bits/stdc++.h>
#include <string>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define rep2(i, b) for (int i = 0; i < b; i++)
#define repl(i, a, b) for (ll i = a; i <= b; i++)
#define ppi pair<int,int>
#define scl(n) scanf("%d",&n);
#define pcl(n) printf("%d\n", n)
#define pcl1(n) printf("%lld ", n)
#define FastRead                  \
	ios_base::sync_with_stdio(0); \
	cin.tie(0)
bool comp(ppi a,ppi b)
{
	return a.first<b.first;
}

int main()
{
	ll l,r,ans,res;
	cin>>l>>r;
	if(r-l>2019)
	{
		cout<<"0\n"<<endl;
	}
	else
	{
		ans=2e18;
		for(ll i=l;i<=r;i++)
		{
			for(ll j=i+1;j<=r;j++)
			{
				res=(i*j)%2019;
				ans=min(ans,res);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}