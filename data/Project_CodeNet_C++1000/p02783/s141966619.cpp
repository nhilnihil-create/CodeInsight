#include <stdio.h>      
int main() {
  
	int H;
	int A;
	scanf("%d %d", &H, &A);
	
	int M = H/A;
	int N = H%A;
	
	N==0?printf("%d\n", M):printf("%d\n", M+1);
	
  return 0;
}
