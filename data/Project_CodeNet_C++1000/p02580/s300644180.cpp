#include<bits/stdc++.h>
#define ll unsigned long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
using namespace std;
const int N=3e5+10;
set<pii>s;
int r[N],c[N],id1[N],id2[N];
int main()
{
	int h,w,m;
	scanf("%d%d%d",&h,&w,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		s.insert(mp(x,y)),r[x]++,c[y]++;
	}
	for(int i=1;i<=h;i++)id1[i]=i;
	for(int i=1;i<=w;i++)id2[i]=i;
	sort(id1+1,id1+1+h,[&](int x,int y){return r[x]>r[y];});
	sort(id2+1,id2+1+w,[&](int x,int y){return c[x]>c[y];});
	int done=0,res=0;
	for(int i=1;i<=h&&r[id1[i]]==r[id1[1]]&&!done;i++)
	for(int j=1;j<=w&&c[id2[j]]==c[id2[1]]&&!done;j++)
	if(s.find(mp(id1[i],id2[j]))==s.end())res=max(res,r[id1[i]]+c[id2[j]]),done=1;
	else res=max(res,r[id1[i]]+c[id2[j]]-1);
	printf("%d\n",res);
	return 0;
}
