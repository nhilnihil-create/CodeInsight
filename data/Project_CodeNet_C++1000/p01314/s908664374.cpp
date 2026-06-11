#include <cstdio>
int main() {
	int N;
	while(scanf("%d",&N),N) {
		int sum=0;
		for(int i=1;i<N;i++) {
			bool OK=0;
			for(int j=1;;j++) {
				int k=(i*2+j)*(j+1)/2;
				if(k==N) {
					OK=1;
					break;
				}else if(k>N) {
					break;
				}
			}
			if(OK) sum++;
		}
		printf("%d\n",sum);
	}
}