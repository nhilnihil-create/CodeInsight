#include <cstdio>
main(){
	int a[4],b[4],ar,br;
	scanf("%d%d%d%d",a,a+1,a+2,a+3);
	scanf("%d%d%d%d",b,b+1,b+2,b+3);
	ar=*a+a[1]+a[2]+a[3],br=*b+b[1]+b[2]+b[3];
	printf("%d\n",ar>br?ar:br);
}