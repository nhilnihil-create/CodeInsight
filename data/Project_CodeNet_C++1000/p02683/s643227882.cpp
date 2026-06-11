#include <cstdio>
#include <vector>
using namespace std;
int n,m,x,ans=0x7fffffff;
int c[15],a[15][15];
int main(){
	scanf("%d%d%d",&n,&m,&x);
	for(int i=1;i<=n;++i){
		scanf("%d",c+i);
		for(int j=1;j<=m;++j){
			scanf("%d",a[i]+j);
		}
	}
	for(int i=0;i<(1<<n);++i){
		int t=i,sum=0;
		vector<int>v(m+1,0);
		for(int j=0;j<n;++j){
			if(t&1){
				for(int k=1;k<=m;++k){
					v[k]+=a[j+1][k];
				}
				sum+=c[j+1];
			}
			t>>=1;
		}
		int j;
		for(j=1;j<=m;++j){
			if(v[j]<x)break;
		}
		if(j>m){
			ans=(sum<ans?sum:ans);
		}
	}
	if(ans==0x7fffffff)printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}
