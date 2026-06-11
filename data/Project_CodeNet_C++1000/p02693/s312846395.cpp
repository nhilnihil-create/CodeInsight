#include <stdio.h>
#include <string.h>

int main(){
	int Tim, Min, Max;  //Times, Minimum, Maximum
	scanf("%d", &Tim);
	scanf("%d %d", &Min, &Max);
	
	for (Min==Min; Min<=Max; Min++){
		if (Min % Tim == 0){
			printf("OK\n");
			return 0;
		} else {
			continue;
		}

	}
	printf ("NG\n");
return 0;
}
