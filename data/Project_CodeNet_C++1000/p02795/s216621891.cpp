#include<stdio.h>
int main(){
    int H, W, N, sum;
    scanf ("%d %d %d", &H, &W, &N);
    if (H > W){
    	sum = N/H ;
    N%H >0 ? printf("%d", sum+1) : printf("%d",sum);
	}
	else  {
		sum = N/W ;
	N%W > 0? printf("%d", sum+1) : printf("%d",sum);
	}
   return 0;
}
