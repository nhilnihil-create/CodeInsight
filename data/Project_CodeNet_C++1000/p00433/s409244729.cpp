#include <cstdio>
main(){
	int a[4],ar[3],n=2;
	while(n--){
	scanf("%d%d%d%d",a,a+1,a+2,a+3);
	ar[n]=*a+a[1]+a[2]+a[3];
	}
	printf("%d\n",*ar>ar[1]?*ar:ar[1]);
}