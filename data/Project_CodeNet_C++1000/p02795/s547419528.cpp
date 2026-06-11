#include<stdio.h>
int main(){
	int row,collom,N,i= 0;
	int tamp,count =0;
	scanf("%d",&row);
	scanf("%d", &collom);
	scanf("%d", &N);
	if(row>collom){
		tamp=row;
	}else{
		tamp=collom;
	}
	for(i=0;i<N;i=i+tamp){
		count++;
	}
	printf("%d",count);
	
	
	return 0;
}