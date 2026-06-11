#include<cstdio>
main(){
	int a[3],buf=4096;
	scanf("%d%d%d",&a[0],&a[1],&a[2]);

	for(int i=0;i<3;i++){
		for(int j=1;j<3;j++){
			if(a[j-1]>a[j]){
				buf = a[j];
				a[j] = a[j-1];
				a[j-1] = buf;
			}
		}
	}
	printf("%d %d %d\n",a[0],a[1],a[2]);
}