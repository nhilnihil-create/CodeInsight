#include <stdio.h>
int cnt[105],tot;
int main(){
	int n,k,m,i,j,a;
	scanf("%d%d",&n,&k);
	for(i=1;i<=k;i++){
		scanf("%d",&m);
		for(j=1;j<=m;j++){
			scanf("%d",&a);
			cnt[a]++;
		}
	}	
	for(i=1;i<=n;i++)
		if(cnt[i])tot++;
	printf("%d\n",n-tot);
	return 0;
}