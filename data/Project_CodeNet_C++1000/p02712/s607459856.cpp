#include <stdio.h>

int main(){
	int input;
	scanf("%d",&input);
 
	long long ans=0;
 
	for(int i = 1; i <= input; i++){
 		if(i % 3 != 0 && i % 5 != 0){
 			ans += i;
			}
		}
 	printf("%lld\n",ans);
 	return 0;
 }
