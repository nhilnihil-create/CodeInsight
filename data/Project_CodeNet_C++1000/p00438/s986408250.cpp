#include <stdio.h>

int main(void)
{
	int a[100][100];
	int x, y;
	int i, j, k;
	int num;
	int ni[40], nj[40];
	
	while (1){
		for (i = 0; i < 100; i++){
			for (j = 0; j < 100; j++){
				a[i][j] = 0;
			}
		}
		
		scanf("%d %d", &x, &y);
		
		if (x == 0 && y == 0){
			break;
		}
		
		scanf("%d", &num);
		for (k = 0; k < num; k++){
			scanf("%d %d", &ni[k], &nj[k]);
		}
		x--;
		y--;
		
		for (k = 0; k < num; k++){
			a[ni[k] - 1][nj[k] - 1] = -1;
		}
		
		a[x - 1][y] = a[x][y - 1] = 1;
		for (i = x; i >= 0; i--){
			for (j = y; j >= 0; j--){
				if (a[i][j] == 0){
					a[i][j] = a[i + 1][j] + a[i][j + 1];
				}
				else if (a[i][j] == -1){
					a[i][j] = 0;
				}
			}
		}
		
		printf("%d\n", a[0][0]);
	}
	
	return (0);
}