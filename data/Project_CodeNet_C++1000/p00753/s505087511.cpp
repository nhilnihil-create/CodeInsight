#include <cstdio>

int num[300000];

void prime(){
	num[0] = 0;
	num[1] = 0;
	for(int i = 2; i < 300000; i++) num[i] = 1;
	for(int i = 2; i < 1000; i++){
		if(!num[i]) continue;
		for(int j = 2*i; j < 300000; j += i){
			num[j] = 0;
		}
	}
}

int main(){
	prime();
	for(int i = 1; i < 300000; i++) num[i] += num[i-1];
	int n;
	while(scanf("%d",&n),n) printf("%d\n", num[2*n]-num[n]);
}