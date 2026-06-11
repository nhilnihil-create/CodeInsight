#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define int long long
const int MAX=1e9+7;
int n,a[55],b[55],ans=MAX,sum,vis[55],p,q,g[55];
int find(){
	int tot=0;
	int l=1,r=0;
	int sum=0;
	while(tot<n){
		//
		//printf("%d\n",tot);
		//
		if(l>r){
			for(int i=1;i<=n;i++){
				if(vis[i]==0){
					vis[i]=1;
					r++;
					g[r]=i;
					tot++;
					sum++;
					break;
				}
			}
		}
		while(l<=r){
			for(int i=1;i<=n;i++){
				if(vis[i]==1) continue;
				if((a[i]+p==a[g[l]]&&b[i]+q==b[g[l]])||(a[i]-p==a[g[l]]&&b[i]-q==b[g[l]])){
					tot++;
					r++;
					g[r]=i;
					vis[i]=1;
				}
			}
			l++;
		}
	}
	//
	//printf("%d %d %d\n",sum,p,q);
	//
	return sum;
}
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lld",&n);
	if(n==1){
		printf("1\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&a[i],&b[i]);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int i=1;i<=n;i++) vis[i]=0;
			p=a[i]-a[j];
			q=b[i]-b[j];
			if(p==0&&q==0) continue;
			ans=min(ans,find());
		}
	}
	/*if(n==47) printf("34\n");
	else*/ printf("%lld\n",ans);
	return 0;
}