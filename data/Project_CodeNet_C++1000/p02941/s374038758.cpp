#include<cstdio>
#include<queue>
using namespace std;
int f[200050],a[200050],n;
bool inq[200050];
inline int lst(int x){return x-1==0?n:x-1;}
inline int nxt(int x){return x+1>n?1:x+1;}
struct node{
	int p;
	node(){}
	node(int p):p(p){}
};
queue<node> Q;
inline bool check(int i){return a[i]>f[i]&&a[i]-f[i]>=a[lst(i)]+a[nxt(i)];}
int main(){
	int i,t1,t2;
	long long ans=0ll;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",f+i);
	for(i=1;i<=n;++i){
		scanf("%d",a+i);
		if(a[i]<f[i]){
			puts("-1");
			return 0;
		}
	}
	for(i=1;i<=n;++i)if(check(i))Q.push(node(i)),inq[i]=1;
	while(!Q.empty()){
		i=Q.front().p;Q.pop();inq[i]=0;
		t1=a[i]-f[i];
		t2=a[lst(i)]+a[nxt(i)];
		ans+=t1/t2;
		a[i]=f[i]+t1%t2;
		if(!inq[lst(i)]&&check(lst(i)))Q.push(lst(i)),inq[lst(i)]=1;
		if(!inq[nxt(i)]&&check(nxt(i)))Q.push(nxt(i)),inq[nxt(i)]=1;
	}
	for(i=1;i<=n;++i)if(f[i]!=a[i]){
		puts("-1");
		return 0;
	}
	printf("%lld\n",ans);
	return 0;
}