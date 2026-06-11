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

int n,m;
vector <int> ans;
char s[maxn];

int main()
{
	n=read(); m=read(); scanf("%s",s);
	int nw=n;
	while(nw!=0)
	{
		int f=0;
		for(int i=max(0,nw-m);i<nw;i++)
		{
			if(s[i]=='0')
			{
				ans.push_back(nw-i);
				nw=i,f=1;  break;
			}
		}
		if(f==0) {puts("-1"); return 0;}
	}
	for(int i=ans.size()-1;i>=0;i--) printf("%d ",ans[i]);
	return 0;
}