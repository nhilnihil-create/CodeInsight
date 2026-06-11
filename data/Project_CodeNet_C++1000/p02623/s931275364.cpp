#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<string.h>
#define fornt(k,n) for(int i=k; i<n; ++i)
#define fornt2(p,n) for(int j=p; j<n; ++j)
#define pb push_back
#define ll long long
#define sc(n) scanf("%d",&n)
#define sc2(x,y) scanf("%d %d",&x,&y)
#define scl(n) scanf("%lld",&n)
#define scl2(x,y) scanf("%lld %lld",&x,&y)
#define pr(n) printf("%d\n",n)
#define prl(n) printf("%lld\n",n)
#define pry printf("YES\n")
#define prn printf("NO\n")
using namespace std;

const int MAX=1e6+7;
unsigned ll a[MAX],b[MAX],x[MAX],y[MAX];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0), cout.tie(0);
    int n,m,k,cnt;
    cin>>n>>m>>k;
	for(int i=0;i<n;i++)
	cin>>a[i];
	for(int i=1;i<n;i++)
	a[i]+=a[i-1];
	for(int i=0;i<m;i++)
	cin>>b[i];
	for(int i=1;i<m;i++)
	b[i]+=b[i-1];
	unsigned ll ans1=0,ans2=0,sum=0;
	for(ll i=0;i<n;i++)
	{
		sum=a[i];
		unsigned ll temp=k-sum;
		if(temp>k)break;
		unsigned ll pos=upper_bound(b,b+m,temp)-b;
		ans1=max(pos+i+1,ans1);
	}
	sum=0;
	for(ll i=0;i<m;i++)
	{
		sum=b[i];
		unsigned ll temp=k-sum;
		if(temp>k)break;
		unsigned ll pos=upper_bound(a,a+n,temp)-a;
		ans2=max(pos+i+1,ans2);
	}
	cout<<max(ans1,ans2);
    return 0;
}
