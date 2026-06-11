#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef vector<int>vi;
#define pb push_back
#define sc(n) scanf("%d",&n)
#define lsc(n) scanf("%lld",&n)
#define all(x) x.begin(),x.end()
#define rep(i,n) for(i=0;i<n;i++)
#define rep1(i,n) for(i=1;i<=n;i++)
#define rev(i,n) for(i=n-1;i>=0;i--)
#define rev1(i,n) for(i=n;i>0;i--)
#define in insert
#define IT ::iterator
#define pr(n) printf("%d\n",n)
#define lpr(n) printf("%lld\n",n);


int main()
{
	int n,i;
	sc(n);
	int a[n],b[n-1];
	rep(i,n-1)
	{
		sc(b[i]);
	}
	ll s=0LL;
	rep(i,n)
	{
		if(i==0)a[0]=b[0];
		else if(i==n-1)a[i]=b[i-1];
		else
		{
			a[i]=min(b[i],b[i-1]);
		}
		s+=(ll)a[i];
	}
	cout << s ;
    return 0;
}
