#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2005;
struct node{
	ll num,no;
};
node p[N];
bool cmp(node node1,node node2) {
	return node1.num<node2.num;
}
ll f[N][N];
ll n;
ll calc(ll x,ll y) {
	if (f[x][y]>-1) return f[x][y];
	if (x>y) return f[x][y]=0;
	ll now=y-x+1;
	f[x][y]=max(p[now].num*abs(p[now].no-x)+calc(x+1,y),p[now].num*abs(p[now].no-y)+calc(x,y-1));
	return f[x][y];
}
int main() {
	ll i,j,ans;
	scanf("%lld",&n);
	for (i=1;i<=n;i++) {
		scanf("%lld",&p[i].num);
		p[i].no=i;
	}
	sort(p+1,p+n+1,cmp);
	for (i=1;i<=n;i++) for (j=1;j<=n;j++) f[i][j]=-1;
	ans=calc(1,n);
	printf("%lld\n",ans);
	return 0;
}