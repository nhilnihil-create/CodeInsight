#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n,m,x;
int c[15];
int a[15][15];
int now[15];

int main(void){
	scanf("%d%d%d",&n,&m,&x);
	for(int i=0;i<n;i++){
		scanf("%d",&c[i]);
		for(int j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	int ans=-1;
	for(int i=0;i<(1<<n);i++){
		memset(now,0,sizeof(now));
		int co=0;
		for(int j=0;j<n;j++){
			if(i>>j & 1){
				for(int k=0;k<m;k++){
					now[k]+=a[j][k];
				}
				co+=c[j];
			}
		}
		bool flag=true;
		for(int j=0;j<m;j++){
			if(now[j]<x){
				flag=false;
			}
		}
		if(flag){
			if(ans==-1){
				ans=co;
			}
			ans=min(ans,co);
		}
	}
	printf("%d\n",ans);
	return 0;
}
