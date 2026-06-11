#include<bits/stdc++.h>
using namespace std;
const int maxn=200100;
int n,a[maxn],b[maxn];
set<pair<int,int> > S;
inline int prev(int x){return x==1?n:x-1;}
inline int nxtv(int x){return x==n?1:x+1;}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<=n;i++) scanf("%d",b+i);
	for(int i=1;i<=n;i++) S.insert(make_pair(b[i],i));
	long long ans=0;
	while(S.size())
	{
		pair<int,int> ttt=*--S.end();S.erase(--S.end());
		int id=ttt.second;if(a[id]==ttt.first) continue;
		int cnt=(b[id]-a[id])/(b[prev(id)]+b[nxtv(id)]);
		if(cnt==0) return puts("-1"),0;
		b[id]-=cnt*(b[prev(id)]+b[nxtv(id)]);
		S.insert(make_pair(b[id],id));ans+=cnt;
	}
	cout<<ans<<endl;
	return 0;
}