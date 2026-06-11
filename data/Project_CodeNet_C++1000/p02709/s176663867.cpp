#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
using namespace std;

const int mn=2006;
int a[mn],id[mn];
long long f[mn][mn],ans;

bool cmp(int x,int y)
{
	return a[x]>a[y];
}

int main()
{
	int n;
	scanf("%d",&n);
	FOR(i,0,n-1) {scanf("%d",a+i);id[i]=i;}
	sort(id,id+n,cmp);
	FOR(i,0,n-1) FOR(j,0,n-i-1) {
		int k=i+j;
		f[i+1][j]=max(f[i+1][j],f[i][j]+1ll*a[id[k]]*abs(id[k]-i));
		f[i][j+1]=max(f[i][j+1],f[i][j]+1ll*a[id[k]]*abs(id[k]-(n-j-1)));
	}
	FOR(i,0,n) ans=max(ans,f[i][n-i]);
	cout<<ans;
}