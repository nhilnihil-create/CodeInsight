#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=54;
int n,m,q;
int a[N],b[N],c[N],d[N];
int A[15];
int ans;
inline int calc() {
	int ret=0;
	for (int i=1;i<=q;++i)
		ret+=(A[b[i]]-A[a[i]]==c[i])*d[i];
	return ret;
}
inline void smax(int &x,int y) {
	x=x>y?x:y;
}
inline void dfs(int step,int l,int r) {
	if (step==n+1) {
		smax(ans,calc());
		return ;
	}
//	if (r-l+1<n-step+1) return;
	for (int i=l;i<=r;++i) {
		A[step]=i;
		dfs(step+1,i,r);
		A[step]=0;
	}
}
int main() {
//	freopen("in2.txt","r",stdin);
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=q;++i) scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
	dfs(1,1,m);
	printf("%d\n",ans);
	return 0;
}