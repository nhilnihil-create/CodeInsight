#include <cstdio>
using namespace std;

int main() {
	int H,W;
	while(1) {
		scanf("%d%d",&H,&W);
		if (H==0 && W==0) break;
		for(int j=0;j<H;++j) {
			for(int i=0;i<W;++i) {
				if(j==0 || i==0 || j==H-1 || i==W-1) {
					printf("#");
				} else {
					printf(".");
				}
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}