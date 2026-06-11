#include<bits/stdc++.h>
using namespace std;
vector<int>a[300001];
struct line{int i,cnt;}b[300001];
int h,w,m,x_[300001],y_[300001],ans,cntx[300001],cnty[300001],vis[300001];
bool cmp(line i,line j){return i.cnt>j.cnt;}
int main()
{
	scanf("%d%d%d",&h,&w,&m);
	for(int i=1;i<=m;i++)scanf("%d%d",&x_[i],&y_[i]),++cntx[y_[i]],++cnty[x_[i]],a[x_[i]].push_back(y_[i]);
	for(int i=1;i<=w;i++)b[i].i=i,b[i].cnt=cntx[i];
	sort(b+1,b+w+1,cmp);
	for(int i=1;i<=h;i++)
	{
		int l1=a[i].size();
		for(int j=0;j<l1;j++)vis[a[i][j]]=i;
		for(int j=1;j<=w;j++)if(vis[b[j].i]!=i){ans=max(ans,cnty[i]+b[j].cnt);break;}
		else ans=max(ans,cnty[i]+b[j].cnt-1);
	}
	printf("%d",ans);
	return 0;
}