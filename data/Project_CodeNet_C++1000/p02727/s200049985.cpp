#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=100010;
int x,y,a,b,c,t,tot;
ll p[MAXN*3],q[MAXN],r[MAXN],ans;
int main () {
	scanf("%d%d%d%d%d",&x,&y,&a,&b,&c);
	for (int i=1;i<=a;i++) {
		scanf("%d",&q[i]);
	}
	sort(q+1,q+a+1);
	for (int i=a;i>=a-x+1;i--) {p[++tot]=q[i];}
	for (int i=1;i<=b;i++) {
		scanf("%d",&r[i]);
	}
	sort(r+1,r+b+1);
	for (int i=b;i>=b-y+1;i--) {p[++tot]=r[i];} 
	for (int i=1;i<=c;i++) {
		scanf("%d",&t);
		p[++tot]=t;
	}
	sort(p+1,p+tot+1);
	for (int i=tot;i>=tot-x-y+1;i--) {
		ans+=p[i];
	}
	printf("%lld\n",ans);
	return 0;
}