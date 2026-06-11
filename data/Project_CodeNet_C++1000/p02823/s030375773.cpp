#include<bits/stdc++.h>
#define ll long long int
#define loop(i,a,b) for(i=a;i<b;i++)
#define mod   998244353
#define INF 1000000000000
#define pb push_back
#define lim 500001
using namespace std;
int main()
{ll n,a,b,ans;

	cin>>n>>a>>b;
	if(abs(a-b)%2==0)
		ans=abs(a-b)/2;
	else
	{ll mx=max(a,b);
		ll mn=a+b-mx;
		ans=min(mn,n-mx+1)+(mx-mn-1)/2;
	}
	cout<<ans<<endl;return 0;}
