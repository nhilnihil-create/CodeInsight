#include <stdio.h>
	int main(){
		int input,suu[101]={0},i,max=0;
		while(scanf("%d",&input)!=EOF){
			suu[input]++;
			if(max<=suu[input]) max=suu[input];
		}
		for(i=1;i<101;i++){
			if(max==suu[i]){
				printf("%d\n",i);
			}
		}
	return 0;
}