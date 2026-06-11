#include<bits/stdc++.h>
#define debug1 cout<<"?"<<endl;
#define debug2 cout<<"?"<<i<<endl;

typedef long long ll;
#define PII pair<ll,ll>
const int maxn=1e6+9;
const double pi=acos(-1);
const int mod=998244353;
const int INF=0x3f3f3f3f;
const double ep=1e-10;
using namespace std;
int main()
{
	int n,i,a[maxn]={0},vis[4]={0};
	char s[maxn];
	scanf("%d",&n);
	scanf("%s",s+1);
	for(i=1;i<=n;i++)a[i]=s[i]-'0'-1,vis[a[i]]=1;
	if(vis[2])
	{
		if(vis[1])
		{
			for(i=1;i<=n;i++)a[i]=a[i]%2;
		}
		else for(i=1;i<=n;i++)if(a[i]==2)a[i]=1;
	}
	int ans=0;
	for(i=0;i<n;i++)
	{
		if(((n-1)&i)==i)ans=(ans+a[i+1])%2;
	}
	if(ans)
	{
		if(vis[1])puts("1");
		else puts("2");
	}
	else puts("0");
}