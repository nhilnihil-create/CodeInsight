#include <stdio.h>
int main(){
	int a1, b1, k;
	scanf("%d", &k);
	scanf("%d %d", &a1, &b1);
	int ans=0;
	for(int i = a1; i <=b1; i++){
		if(i%k==0){
			ans++;
		}
	}if(ans>0){
		printf("OK\n");
	}else {
		printf("NG\n");
	}
	
	return 0;
}
