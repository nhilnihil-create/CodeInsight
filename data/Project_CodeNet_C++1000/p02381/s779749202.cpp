#include<stdio.h>
#include<math.h>
int main(){
	int n,i;
	int ten[1000];
	double hei,a,bun,gou=0;
	
	while(1){
	scanf("%d",&n);
	if(n==0){
		break;
	}
	for(i=0;i<n;i++){
		scanf("%d",&ten[i]);
		gou += ten[i];
	}
	hei = gou/n;
	for(i=0;i<n;i++){
		a += pow(ten[i] - hei,2.0);
	}
	bun = sqrt(a/n);
	printf("%.8f\n",bun);
	gou=0;
	a=0;
	}
}