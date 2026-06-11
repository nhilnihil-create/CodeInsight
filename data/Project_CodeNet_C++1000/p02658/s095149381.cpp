#include <stdio.h>

int main() {
	long long int x;
	scanf("%lld", &x);
	long long int y[x];
	long long int total=1;
	
	for(int i=0;i<x;i++){
		scanf("%lld", &y[i]);
	}
	
	for(int j=0;j<x;j++) {
		if(y[j]==0) {
			printf("0");
			return 0;
		}
	}
	for(int k=0;k<x;k++) {
		if(y[k]<=1000000000000000000/total) {
			total=total*y[k];
		}

	else {
		printf("-1");
		return 0;
	}

}
	printf("%lld",total);
	return 0;
}