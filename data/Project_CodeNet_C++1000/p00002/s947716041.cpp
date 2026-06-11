#include <stdio.h>
int main(void){
	int a,b;
	while(scanf("%d %d",&a,&b)!=EOF){
		int sum=a+b;
		int digit=1;
		while(1){
			if(sum/10>0){
				sum/=10;
				digit++;
			}else {
				break;
			}
		}
		printf("%d\n",digit);
	}
	return 0;
}