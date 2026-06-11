#include<bits/stdc++.h>
using namespace std;
const int maxn=51;
pair<int,int> a[maxn];
int n,vis[maxn];
map<pair<int,int>,int> ID;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) ID[a[i]]=i;
	if(n==1) return puts("1"),0;
	int ans=n;
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
	{
		for(int k=1;k<=n;k++) vis[k]=0;
		int dx=a[j].first-a[i].first,dy=a[j].second-a[i].second;
		int cnt=0;
		for(int k=1;k<=n;k++) if(!vis[k])
		{
			int nowx=a[k].first,nowy=a[k].second;cnt++;
			while(ID[make_pair(nowx,nowy)])
				vis[ID[make_pair(nowx,nowy)]]=1,nowx+=dx,nowy+=dy; 
		}
		ans=min(ans,cnt);
	}
	cout<<ans<<endl;
}