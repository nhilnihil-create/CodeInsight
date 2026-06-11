#include <cstdio>
using namespace std;
const int M=10,MQ=50;
int w[M+5],a[MQ+5],b[MQ+5],c[MQ+5],d[MQ+5];
int n,m,q,ans;
void dfs(int x,int y){
	if(x>m){
		int A[M+5]={0};
		for(int i=1;i<=m;++i){
			A[w[i]]++;
		}
		int sum=0,cnt=0;
		for(int i=0;i<=n;++i){
			int t=A[i];
			A[i]=sum;
			sum+=t;
		}
		for(int i=1;i<=q;++i){
			if(A[b[i]]-A[a[i]]==c[i])cnt+=d[i];
		}
		ans=(cnt>ans?cnt:ans);
		return;
	}
	for(int i=y;i<=n;++i){
		w[x]=i;
		dfs(x+1,i);
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=q;++i){
		scanf("%d%d%d%d",a+i,b+i,c+i,d+i);
	}
	w[1]=0;
	dfs(2,1);
	printf("%d\n",ans);
	return 0;
}