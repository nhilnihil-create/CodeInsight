#include <stdio.h>

int main()
{
	int A[3][3]; for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) scanf ("%d", &A[i][j]);
	int n; scanf ("%d", &n); while (n--){
		int x; scanf ("%d", &x);
		for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) if (A[i][j] == x) A[i][j] = -1;
	}

	for (int i = 0; i < 3; i++) if (A[i][0] == -1 && A[i][1] == -1 && A[i][2] == -1){
		puts("Yes"); return 0;
	}
	for (int i = 0; i < 3; i++) if (A[0][i] == -1 && A[1][i] == -1 && A[2][i] == -1){
		puts("Yes"); return 0;
	}
	if (A[0][0] == -1 && A[1][1] == -1 && A[2][2] == -1){
		puts("Yes"); return 0;
	}
	if (A[2][0] == -1 && A[1][1] == -1 && A[0][2] == -1){
		puts("Yes"); return 0;
	}
	puts("No");
	return 0;
}