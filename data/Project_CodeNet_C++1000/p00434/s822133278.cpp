#include<stdio.h>

int main(void){
	int i,tei;
	int st[31];
	for(i=1;i<31;i++)st[i]=0;
	for(i=0;i<28;i++){
		scanf("%d",&tei);
		st[tei]+=tei;
	}
	for(i=1;i<32;i++){
		if(st[i]==0)
			printf("%d\n",i);
	}
	return 0;
}