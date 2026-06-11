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
	int a[n+1],b[n+1],c[n];
	rep1(i,n)
	{
		sc(a[i]);
	}
	rep1(i,n)
	{
		sc(b[i]);
	}
	rep1(i,n-1)
	{
		sc(c[i]);
	}
	int tot=0;
	rep1(i,n)
	{
		tot+=b[a[i]];
		if(i!=1)
		{
			if(a[i]-a[i-1]==1)
			{
				tot+=c[a[i-1]];
			}
		}
	}
	cout << tot << endl;
    return 0;
}
