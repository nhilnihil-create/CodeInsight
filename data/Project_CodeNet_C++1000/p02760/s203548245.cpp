#include <stdio.h>
 
int main () {
	int a[3][3];
	int count = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	int n, m, b[3][3];
	scanf("%d", &n);
	for ( int i = 0; i < n; i++) {
		scanf("%d", &m);
		
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (a[i][j] == m) {
					b[i][j] = 1;
				}
			}
		}
	}
	
	if (b[0][0]+ b[1][1]+ b[2][2] == 3 || b[0][2]+ b[1][1]+ b[2][0] == 3) {
      printf("Yes\n");
      return 0;
    }
	
	for(int i = 0; i < 3; i++) {
      if(b[i][0]+ b[i][1]+ b[i][2] == 3 || b[0][i]+ b[1][i]+ b[2][i] == 3) {
        printf("Yes\n");
        return 0;
       }
    }
	printf("No\n");
	
	return 0;
}