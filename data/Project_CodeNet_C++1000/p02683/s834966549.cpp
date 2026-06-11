#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2000000+234;
int n,m,x,c[50],a[50][50],mini=INT_MAX;
int main(){
	scanf("%d%d%d",&n,&m,&x);
	for(int i=0;i<n;i++){
		scanf("%d",&c[i]);
		for(int j=0;j<m;j++)scanf("%d",&a[i][j]);
	}
	for(int i=0;i<(1<<n);i++){//枚举所有可能的方案，每一个i对应一个方案
		int sum[50],cost=0;
		memset(sum,0,sizeof(sum));
		for(int j=0;j<n;j++)
			if(i&(1<<j)){
				for(int k=0;k<m;k++)sum[k]+=a[j][k];
				cost+=c[j];
			}//i的第j位是1，在i的方案中，包含j这本书
//		cout<<i<<":"<<cost;
//		for(int k=0;k<m;k++)cout<<" "<<sum[k];
//		cout<<endl;
		bool f=1;
		for(int k=0;k<m;k++)
			if(sum[k]<x){f=0;break;}
		if(f==1)mini=min(mini,cost);
	}
	if(mini==INT_MAX)printf("%d",-1);
	else printf("%d",mini);
	return 0;
}