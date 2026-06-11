#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define LL long long
#define pii pair <LL,LL>
#define fi first
#define se second
#define pb push_back
#define mpr make_pair

using namespace std;

const LL MOD=1e9+7;

LL n,x,y,ans=0;

int main()
{
	cin>>n;
	repn(i,n) ans+=(LL)(1+i)*(LL)i/2;
	rep(i,n-1)
	{
		scanf("%lld%lld",&x,&y);
		if(x>y) swap(x,y);
		ans-=x*(n-y+1);
	}
	cout<<ans<<endl;
	return 0;
}