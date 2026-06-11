#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<queue>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
const int N=10000;
const db pi=acos(-1.0);
#define lowbit(x) (x)&(-x)
#define sqr(x) (x)*(x)
#define rep(i,a,b) for (register int i=a;i<=b;i++)
#define per(i,a,b) for (register int i=a;i>=b;i--)
#define fir first
#define sec second
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define maxd 998244353
#define eps 1e-8
int n,a[300300],b[300300],sum[300300],m,cnt[300300],ans[300300];

int read()
{
    int x=0,f=1;char ch=getchar();
    while ((ch<'0') || (ch>'9')) {if (ch=='-') f=-1;ch=getchar();}
    while ((ch>='0') && (ch<='9')) {x=x*10+(ch-'0');ch=getchar();}
    return x*f;
}

bool chk(int k,int tim)//每次选k个减1，能否减tim次 
{
	//cout << k << " " << tim << " " << sum[tim-1] << " " << (k-cnt[tim])*tim << endl;
	return sum[tim-1]>=1ll*(k-cnt[tim])*tim;
}

int main()
{
	n=read();
	rep(i,1,n) a[read()]++;
	rep(i,1,n)
		if (a[i]) b[++m]=a[i];
	sort(b+1,b+1+m);
	//rep(i,1,m) cout << b[i] << " ";cout << endl;
	rep(i,1,m) sum[b[i]]+=b[i];
	rep(i,1,n) sum[i]+=sum[i-1];
	rep(i,1,m) cnt[b[i]]++;
	per(i,n,1) cnt[i]+=cnt[i+1];
	rep(i,1,n)
	{
		int l=1,r=n;
		//cout << i << endl;
		while (l<=r)
		{
			int mid=(l+r)>>1;
			if (chk(i,mid)) {ans[i]=mid;l=mid+1;}
			else r=mid-1;
		}
	}
	rep(i,1,n) printf("%d\n",ans[i]);
	return 0;
}
