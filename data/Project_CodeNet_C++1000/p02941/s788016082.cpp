#include<cstdio>
#include<queue>
#define mk make_pair
using namespace std;
typedef pair<int,int> pr;
const int N=200005;

int n,cnt;
int a[N],b[N];
long long ans;
priority_queue<pr>Q;
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) {
		scanf("%d",&b[i]);
		if(b[i]!=a[i])
			Q.push(mk(b[i],i));
	}
	b[0]=b[n]; b[n+1]=b[1];
	while(!Q.empty()) {
		pr now=Q.top(); Q.pop();
		int p=now.second;
		int dir=(b[p]-a[p])/(b[p-1]+b[p+1]);
		if(dir<=0) {
			printf("-1\n");
			return 0;
		}
		b[p]=b[p]-dir*(b[p-1]+b[p+1]);
		if(p==1) b[n+1]=b[p];
		if(p==n) b[0]=b[p];
		ans+=dir;
		if(b[p]!=a[p])
			Q.push(mk(b[p],p));
	}
	printf("%lld\n",ans);
	return 0;
}
