#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;
const int M=3e5+5;
int cntx[M],cnty[M];

set<PII> se;

int main()
{
	int h,w,m; scanf("%d%d%d",&h,&w,&m);
	int x,y;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		cntx[x]++;
		cnty[y]++;
		se.emplace(x,y);
	}
	int mx=0,my=0;
	for(int i=1;i<=h;i++)
		mx=max(mx,cntx[i]);
	for(int i=1;i<=w;i++)
		my=max(my,cnty[i]);
	vector<int> vx,vy;
	for(int i=1;i<=h;i++)
		if(cntx[i]==mx) vx.push_back(i);
	for(int i=1;i<=w;i++)
		if(cnty[i]==my) vy.push_back(i);
	int f=0;
	int ans=mx+my-1;
	for(int i:vx)
	{
		for(int j:vy)
		{
			if(!se.count({i,j}))
			{
				ans=mx+my;
				f=1;
				break;
			}
		}
		if(f) break;
	}
	printf("%d\n",ans);
	return 0;
}