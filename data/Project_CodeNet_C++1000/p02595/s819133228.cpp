#include <stdio.h>
#include <math.h>

#pragma warning(disable:4996)


typedef struct {int X; int Y;} Point;

int main() {
	Point point;

	int N, D;
	(void)scanf("%d%d", &N, &D);


	int sum = 0;

	for (int i = 0; i < N; i++) {
		(void)scanf("%d%d", &point.X, &point.Y);
		double Buffer = (double)point.X * (double)point.X + (double)point.Y * (double)point.Y;
		if (sqrt(Buffer) <= D) sum++;
	}
	printf("%d", sum);
}