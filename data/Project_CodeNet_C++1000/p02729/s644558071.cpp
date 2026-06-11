#include <stdio.h>
#include <string.h>

int main(){
	int E, O;
	scanf ("%d %d", &E, &O);
	int sum = 0;
	for (int i=1; i<E; i++){
		sum+=i;
	}
	for (int i=1; i<O; i++){
		sum+=i;
	}
	printf ("%d", sum);


return 0;
}