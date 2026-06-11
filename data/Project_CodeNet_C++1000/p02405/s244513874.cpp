#include <cstdio>
#include <cmath>
using namespace std;


int main (void)
{
	int h, w;
	int i, j;

	while (scanf("%d %d", &h, &w) != EOF && h != 0 || w != 0){
		for (i=1; i<=h; i++){
			for (j=1; j<=w; j++){
				if (i%2 == 0){
					if (j%2 != 0)
						printf(".");
					else
						printf("#");
				}
				else{
					if (j%2 != 0)
						printf("#");
					else
						printf(".");
				}
			}
			printf("\n");
		}
		printf("\n");
	}

	return 0;
}