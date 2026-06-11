#define scanf_s scanf
//#define gets_s gets
#include <stdio.h>
#include <string>
#include <iostream>
#include <math.h>
using namespace std;
#define MAX 50//00
#define MIN -100001
#define _MAX 100
#define g 9.8
#define d 4.9
int main(void)
{
	int a[4], b[4], hit = 0, blow = 0;
	while (scanf_s("%d %d %d %d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &b[0], &b[1], &b[2], &b[3]) != EOF) {
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				if (b[i] == a[j]) {
					if (i == j) ++hit;
					else ++blow;
				}
			}
		}
		printf("%d %d\n", hit, blow);
		hit = blow = 0;
	}
}