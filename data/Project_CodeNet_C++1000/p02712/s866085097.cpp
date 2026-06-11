#include <stdio.h>

int main(){
	int N;
	scanf("%d",&N);
	long long hasil=0;
	for (int i=1;i<=N;i++){
		if(i%3==0&&i%5==0){
			continue;
		}else if(i%3==0){
			continue;
		}else if(i%5==0){
			continue;
		}else {
			hasil += i;
		}
	}
	printf("%lld",hasil);
return 0;
}