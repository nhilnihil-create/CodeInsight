#include<stdio.h>

int main(){
	int n,i,j,k,cnt;
	while(1){
		scanf("%d",&n);
		if(!n)break;
		cnt=0;
		for(i=2;i<n;i++){ //
			for(j=1;i+j<=n;j++){ // min_fact
				if(n==((2*j-1+i)*i/2))cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}