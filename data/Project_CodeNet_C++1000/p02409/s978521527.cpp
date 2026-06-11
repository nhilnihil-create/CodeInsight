#include<stdio.h>
int main(){
	int n,b,f,r,v;
	scanf("%d",&n);
	int s[4][3][10]={};
	for(int a=0;a<n;a++){
		scanf("%d %d %d %d",&b,&f,&r,&v);
		s[b-1][f-1][r-1]=s[b-1][f-1][r-1]+v;
	}
	for(int c=0;c<4;c++){
		for(int d=0;d<3;d++){
			for(int e=0;e<10;e++){
				printf(" %d",s[c][d][e]);
			}
			printf("\n");
		}
		if(c==3)break;
		printf("####################");
		printf("\n");
	}
	
	return 0;
}