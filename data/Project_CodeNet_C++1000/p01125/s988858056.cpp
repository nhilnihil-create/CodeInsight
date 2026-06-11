#include <stdio.h>
#include <string.h>

typedef struct {
	int x, y;
} POINT;

int main(void)
{
	POINT p;
	char field[21][21];
	int n, m;
	
	while (1){
		memset(field, 0, sizeof(field));
		scanf("%d", &n);
		if (!n) break;
		for (int i = 0; i < n; i++){
			int x, y;
			
			scanf("%d%d", &x, &y);
			field[x][y] = 1;
		}
		p.x = p.y = 10;
		if (field[10][10] == 1){
			n--;
		}
		field[10][10] = 0;
		
		scanf("%d", &m);
		for (int i = 0; i < m; i++){
			char d[2];
			int step;
			
			scanf("%s%d", d, &step);
			for (int i = 0; i < step; i++){
				switch (d[0]){
				  case 'N': p.y++; break;
				  case 'E': p.x++; break;
				  case 'S':	p.y--; break;
				  case 'W': p.x--; break;
				}
				if (field[p.x][p.y] == 1){
					n--;
					field[p.x][p.y] = 0;
				}
			}
		}
		
		printf("%s\n", n == 0 ? "Yes" : "No");
	}
	
	return (0);
}