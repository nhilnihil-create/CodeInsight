#include <cstdio>
int main(){
	int m, d, c = 0;
	scanf("%d %d", &m, &d);
	for (int i = 2; i < 10; i++){
		for (int j = 2; j < 10; j++){
			if (i * 10 + j > d) continue;
			if (1 <= i * j && i * j <= m){
				c++;
			}
		}
	}
	printf("%d", c);
}