#include <stdio.h>

int main(){
	int h1, m1, h2, m2, k;
	scanf("%d %d %d %d %d", &h1, &m1, &h2, &m2, &k);
	int hour = (h2 - h1) * 60;
	int minute = m2 - m1;
	int time = (hour + minute) - k;
	printf("%d", time);
	return 0;
}