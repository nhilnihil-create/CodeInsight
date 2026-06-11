#include <stdio.h>

/*
constraints
- ALL values in input are integers.
- 1 <= A <= B <= 1000
- 1 <= K <= 1000
*/

int main (){
	// multiple of K
	int k, multiK;
	
	// carry distance A - B
	int a, b;
	
	// if he can achieve the objective print OK
	// if he can't achieve the objective print NG
	scanf ("%d", &k);
	scanf ("%d %d", &a, &b);
	
	for (int i = a; i <= b; i++){
		if (i % k == 0) {
			printf ("OK");
			return 0;
		}
		else {
			continue;
		}
	}
	printf ("NG");
	return 0;
	}