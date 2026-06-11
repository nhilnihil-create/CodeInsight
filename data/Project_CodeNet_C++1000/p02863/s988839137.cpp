#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define fi first
#define se second
using namespace std;

const int mn=3007;

int main()
{
	int n,t,a,b,f[mn];
	pair<int,int> p[mn];
	scanf("%d%d",&n,&t);
	FOR(i,1,n) {scanf("%d%d",&a,&b);p[i]=make_pair(a,b);}
	sort(p+1,p+n+1);
	FOR(i,1,n) for(int j=t-1;j>=0;--j) {
		int c=min(j+p[i].fi,t);
		f[c]=max(f[c],f[j]+p[i].se);
	}
	printf("%d",f[t]);
}