#include <stdio.h>

int main(){
	int a,t;
	long long int sum=0;
	scanf("%d",&a);
	for(int i=0;i<=a;i++){
		if(i%3!=0&&i%5!=0){
			sum+=i;
	}			
}
	printf("%lld",sum);
	return 0;
}