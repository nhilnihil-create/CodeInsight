#include <stdio.h>

int main(){
	int N;
	scanf("%d",&N);
	char A[N+1];
	int lol=1;
	scanf("%s",A);
	if(N%2==0){
		for(int i=0;i<N/2;i++){
			if(A[i]!=A[(N/2)+i]){
				lol=0;
			}
		}
	}else if(N%2==1){
		lol=0;
	}
	if(lol==0){
		printf("No\n");
	}else{
		printf("Yes\n");
	}
return 0;
}