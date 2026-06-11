#include <stdio.h>

int main(){
	int row, col, n;
	scanf("%d", &row);
	scanf("%d", &col);
	scanf("%d", &n);
	
	if (row>col){
		n%row > 0 ? printf("%d", (n/row)+1) : printf("%d", (n/row));
	}
	else {
		n%col > 0 ? printf("%d", (n/col)+1) : printf("%d", (n/col));
	}
	return 0;
}