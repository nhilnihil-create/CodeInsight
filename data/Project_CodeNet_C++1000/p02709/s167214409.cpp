#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll dp[2010][2010];
struct X{
	int pos;
	ll num;
}a[2010];
bool cmp(const X& a,const X& b) {
	return a.num>b.num;
}
ll dfs(int pos,int l,int r) {
//	printf("%d %d %d\n",pos,l,r);
	if(l>r) return 0;
	if(dp[l][r]!=-1) return dp[l][r];
	ll lnum=dfs(pos+1,l+1,r)+a[pos].num*abs(a[pos].pos-l),rnum=dfs(pos+1,l,r-1)+a[pos].num*abs(a[pos].pos-r);
	return dp[l][r]=max(lnum,rnum);
}
int main()
{
	memset(dp,-1,sizeof(dp));
	scanf("%d",&n);
	for(int i=1;i<=n;++i) {
		a[i].pos=i;
		scanf("%lld",&a[i].num);
	}
	sort(a+1,a+n+1,cmp);
	printf("%lld",dfs(1,1,n));
	return 0;
}