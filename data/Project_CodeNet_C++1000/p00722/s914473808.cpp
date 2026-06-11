#include <stdio.h>

int MAX_prime = 1000000;
int a[2000000];

int main(void)
{
	int dummy = 0;
	int n,ans,b,d;
	for(int i = 0; i < MAX_prime; i++){
		a[i] = 1;
	}
	for(int i = 2; i < MAX_prime; i++){
		if(a[i]){
			for(int j = i * 2;j < MAX_prime; j = j + i){
					a[j] = 0;
			}
		}
	}
	a[1] = 0;
	/*
	scanf("%d",&n);
	while(n != 0){
		ans = 0;
		for(int i = n + 1; i <= 2 * n; i++){
			if(a[i]){
				ans++;
			}
		}
		printf("%d\n",ans);
		scanf("%d",&n);
	}
	*/
	scanf("%d %d %d",&b,&d,&n);
	while(n != 0){
		dummy = b;
		while(n > 0){
			if(a[dummy]){
				n--;
			}
			if(n == 0){
				ans = dummy;
			}
			dummy += d;
		}
		printf("%d\n",ans);
		scanf("%d %d %d",&b,&d,&n);
	}
	return 0;
}