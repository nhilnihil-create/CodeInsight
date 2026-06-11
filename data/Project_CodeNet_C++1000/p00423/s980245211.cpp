#include<stdio.h>

int main(){
	int n;
	int i;
	int left,right;
	while(1){
		left = 0;
		right = 0;
		
		scanf("%d",&n);
		if(n == 0 ){
			break;
		}
		for(i = 0; i < n ;i++){
			int a, b;
			scanf("%d %d\n",&a,&b);
			if(a>b){
				left += a+b;
			}else if(a==b){
				left += a;
				right += b;
			}else { // a<b
				right += a+b;
			}
		}
		printf("%d %d\n",left,right);
	}
	return 0;
}