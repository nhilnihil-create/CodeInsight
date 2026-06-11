#include <stdio.h>

int main() {
	int hour1, hour2, min1, min2, t, wake = 0, sleep = 0;
	scanf("%d %d %d %d %d", &hour1, &min1, &hour2, &min2, &t);
	
	wake = (hour1 * 60) + min1;
	sleep = (hour2 * 60) + min2;
	
	if((sleep - wake) > t) {
		printf("%d", sleep - wake - t);
	} else {
		printf("0");
	}
		
	return 0;
}