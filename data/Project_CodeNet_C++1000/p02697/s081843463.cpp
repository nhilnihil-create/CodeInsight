#include <stdio.h>
int main(){
	int n,m,i,t,l,r;
	scanf("%d%d",&n,&m);
	if(n%2==0)n--;
	t=(n-1)/2;
	if(t==1)return 0*printf("1 2\n");
	l=t/2,r=l+2;
	for(i=1;i<=m;i++){
		printf("%d %d\n",l,r);
		l--,r++;
		if(l==0)l=(t+n+1)/2,r=l+1;
	}
	return 0;
}