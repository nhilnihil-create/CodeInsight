#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int a[maxn],sum,ans,n,k,b[maxn];

inline bool jud(int x)
{
	for(int i=1;i<=n;i++) b[i]=a[i]%x;
	sort(b+1,b+n+1);
	int l=1,r=n,nl=0,nr=0;
	while(nl<=k) {nl+=b[l]; l++;} l--;
	while(nr<=k) {nr+=(x-b[r]); r--;} r++;
	if(l-1>=r) return true; return false;
}

int main()
{
	n=5; k=2;
	n=read(); k=read(); ans=1;
	for(int i=1;i<=n;i++) a[i]=read(),sum+=a[i];
	for(int i=2;i*i<=sum;i++)
	{
		if(sum%i==0)
		{
			if(jud(i)) ans=max(ans,i);
			if(jud(sum/i)) ans=max(ans,sum/i);
		}
	}
	if(jud(sum)) ans=max(ans,sum);
	cout<<ans<<endl;
	return 0;
}