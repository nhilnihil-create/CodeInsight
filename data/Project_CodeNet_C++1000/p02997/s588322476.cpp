#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define eps 1e-10
#define pb push_back
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int n,k;
vector <int> a1,a2;

int main()
{
	cin>>n>>k;
	int tot=(n-1)*(n-2)/2,f=n+1;
	if(k>tot) puts("-1");
	else
	{
		for(int i=2;i<=n;i++) a1.pb(1),a2.pb(i);
		int res=(n-1)*(n-2)/2-k,cnt=0;
		if(res==0)
		{
			cout<<a1.size()<<endl;
			for(int k=0;k<a1.size();k++) printf("%d %d\n",a1[k],a2[k]);
			return 0;
		}
		for(int i=2;i<=n;i++) for(int j=i+1;j<=n;j++)
		{
			a1.pb(i),a2.pb(j),cnt++;
			if(cnt==res)
			{
				cout<<a1.size()<<endl;
				for(int k=0;k<a1.size();k++) printf("%d %d\n",a1[k],a2[k]);
				return 0;
			}
		}
	}
	return 0;
}