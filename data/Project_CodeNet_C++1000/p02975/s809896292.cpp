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

int n,b[5],cnt;
set <int> s;
map <int,int> mp;

int main()
{
	n=read();
	for(int i=1;i<=n;i++) {int x=read(); s.insert(x); mp[x]++;}
	if(s.size()==1)
	{
		if(*s.begin()==0) puts("Yes");
		else puts("No");
	}
	else if(s.size()==2)
	{
		if(*s.begin()!=0||n%3!=0||mp[*s.begin()]!=n/3) puts("No");
		else puts("Yes");
	}
	else if(s.size()==3)
	{
		if(*s.begin()==0||n%3!=0) puts("No");
		else
		{
			int f=0;
			for(set <int>::iterator it=s.begin();it!=s.end();it++)
			{
				b[++cnt]=*it;
				if(mp[*it]!=n/3) f=1;
			}
			if(f==0&&b[1]==(b[2]^b[3])) puts("Yes");
			else puts("No");
		}
	}
	else puts("No");
	return 0;
}