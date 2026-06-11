#include<stdio.h>

int kumi;

int saiki(int n,int s,int k){
	if(s==0 && n==0){
		++kumi;
		return 0;
	}
	
	int i;
	for(i=k+1;i<10;i++){
		saiki(n-1,s-i,i);
	}
	return 0;
}
		

main(){
	int n,s,i;
	
	while(0<=scanf("%d%d",&n,&s)){
		if(n==0 && s==0)break;
		kumi=0;
		for(i=0;i<10;i++){
			saiki(n-1,s-i,i);
		}
		printf("%d\n",kumi);
	}
	return 0;
}