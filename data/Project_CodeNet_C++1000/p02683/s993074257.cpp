#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;

int pr[16],ex[16][16],mi=0x3f3f3f3f,sum,now[16];
int n,m,x;
void solve(int u)
{
	int flag=1;
	for(int i=1;i<=m;++i)
	{
		if(now[i]<x)flag=0;
	}
	if(flag){if(sum<mi)mi=sum;return;}
	for(int i=u;i<=n;++i)
	{
		for(int j=1;j<=m;++j)now[j]+=ex[i][j];
		sum+=pr[i];
		solve(i+1);
		for(int j=1;j<=m;++j)now[j]-=ex[i][j];
		sum-=pr[i];
	}
	//cout<<1;
}
int main()
{
	ios;
	cin>>n>>m>>x;
	for(int i=1;i<=n;++i)
	{
		cin>>pr[i];
		for(int j=1;j<=m;++j)cin>>ex[i][j];
	}
	//cout<<1;
	solve(1);
	if(mi!=0x3f3f3f3f)cout<<mi<<'\n';
	else cout<<-1<<'\n';
}