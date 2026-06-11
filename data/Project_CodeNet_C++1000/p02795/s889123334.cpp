#include<stdio.h>
int main(){
    
	int H, W, N;
	int max, min;
    scanf("%d%d%d", &H, &W, &N);

    if(H>W){
    	max = H;
    	min = W;
	} else {
		max = W;
		min = H;
	}
	
	for(int i=1;i<=min;i++){
		if(i*max >= N){
			printf("%d", i);
			return 0;		
		} 
	}

}