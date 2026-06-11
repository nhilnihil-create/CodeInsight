#include<bits/stdc++.h>
#define INF 2147483640
using namespace std;
int c[20],a[20][20],n,m,x,ans;
void check(int k)
{
	int cost=0,u[20]={0};
	for(int i=0; i<n; i++)
		if(k&(1<<i))
		{
			cost+=c[i];
			for(int j=0; j<m; j++) u[j]+=a[i][j];
		}
	int ok=1;
	for(int i=0; i<m; i++) if(u[i] < x){ok=0; break;}
	if(ok) ans=min(ans,cost);
}
int main()
{
	//freopen("out.txt","w",stdout);
	cin >> n >> m >> x;
	for(int i=0; i<n; i++)
		for(int j=0; j<m+1; j++)
			if(!j) cin >> c[i];
			else cin >> a[i][j-1];
	ans=INF;
	for(int i=1; i<(1<<n); i++)
	{
		check(i);
	}
	cout << (ans==INF?-1:ans);
	return 0;
}