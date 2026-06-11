#include <bits/stdc++.h>
using namespace std;
int n,m,x,sum,ans=1e9;
vector<vector<int> >a;
vector<int>c;
int b;
int main(){
	scanf("%d%d%d",&n,&m,&x);
	a.resize(n,vector<int>(m));
	c.resize(n);
	for(int i=0;i<n;i++){
		scanf("%d",&c[i]);
		for(int j=0;j<m;j++)scanf("%d",&a[i][j]);
	}
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<m;j++){
			b=0;
			for(int k=0;k<n;k++){
				if(i&(1<<k))b+=a[k][j];
			}
			if(b<x){
				b=-1;
				break;
			}
		}
		if(b!=-1){
			sum=0;
			for(int k=0;k<n;k++){
				if(i&(1<<k))sum+=c[k];
			}		
			ans=min(ans,sum);
		}
	}
	if(ans==1e9)printf("%d",-1);
	else printf("%d",ans);
	return 0;
}