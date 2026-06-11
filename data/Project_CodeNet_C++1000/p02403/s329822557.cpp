#include <cstdio>
#include <cmath>
using namespace std;


int main (void)
{
	int h, w;
	int i, j;

	while (scanf("%d %d", &h, &w) != EOF && h != 0 || w != 0){
		for (i=0; i<h; i++){
			for (j=0; j<w; j++){
				printf("#");
			}
			printf("\n");
		}
		printf("\n");
	}


	return 0;
}