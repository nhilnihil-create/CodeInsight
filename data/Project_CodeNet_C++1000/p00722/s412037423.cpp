#include <cstdio>

int a,d,n;
bool num[1000000];

int prime(){
	num[0] = false;
	num[1] = false;
	for(int i = 2; i < 1000000; i++) num[i] = true;
	for(int i = 2; i < 1000; i++){
		if(!num[i]) continue;
		for(int j = 2*i; j < 1000000; j += i) num[j] = false;
	}
}

int main(){
	prime();
	while(scanf("%d%d%d", &a, &d, &n),a||d||n){
		int cnt = 0;
		for(int i = 0;;i++){
			if(num[a+d*i]) cnt++;
			if(cnt == n){
				printf("%d\n", a+d*i);
				break;
			}
		}
	}
}