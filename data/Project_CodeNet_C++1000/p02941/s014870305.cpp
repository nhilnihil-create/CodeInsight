#include<bits/stdc++.h>
using namespace std;

typedef long long lint;
typedef long double louble;

template<typename T1,typename T2> inline T1 max(T1 a,T2 b){return a<b?b:a;}
template<typename T1,typename T2> inline T1 min(T1 a,T2 b){return a<b?a:b;}

namespace ae86
{
	const int bufl = 1<<15;

	char buf[bufl],*s=buf,*t=buf;

	inline int fetch()
	{
		if(s==t){t=(s=buf)+fread(buf,1,bufl,stdin);if(s==t)return EOF;}
		return *s++;
	}

	inline int ty()
	{
		int a=0;int b=1,c=fetch();
		while(!isdigit(c))b^=c=='-',c=fetch();
		while(isdigit(c))a=a*10+c-48,c=fetch();
		return b?a:-a;
	}
}
using ae86::ty;

const int _ = 200007;

int n,val[_],tar[_];
priority_queue<pair<int,int>> q;

int main()
{
	n=ty();
	for(int i=0;i<n;i++)tar[i]=ty();
	for(int i=0;i<n;i++)val[i]=ty();

	lint cnts=0;
	for(int i=0;i<n;i++)if(val[i]!=tar[i])q.emplace(val[i],i);
	while(!q.empty())
	{
		int a=q.top().second,sv=val[(a+1)%n]+val[(a-1+n)%n];q.pop();
		int tim=(val[a]-tar[a])/sv;
		if(tim<=0){puts("-1");return 0;}
		val[a]-=sv*tim,cnts+=tim;
		if(val[a]!=tar[a])q.emplace(val[a],a);
	}
	printf("%lld\n",cnts);

	return 0;
}
