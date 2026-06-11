#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
int n;
# define M_PI           3.14159265358979323846 
void printKoch(int step,double x1,double y1,double x5,double y5) {
	if (step == n) {
		printf("%.8f %.8f\n", x5, y5);
		return;
	}
	double x2 = x5 / 3 + x1 * 2 / 3;
	double y2 = y5 / 3 + y1 * 2 / 3;

	double x4 = x1 / 3 + x5 * 2 / 3;
	double y4 = y1 / 3 + y5 * 2 / 3;

	double th = M_PI * 60.0 / 180.0;
	double x3 = (x4 - x2)* cos(th) - (y4 - y2) * sin(th) + x2;
	double y3 = (x4 - x2)* sin(th) + (y4 - y2) * cos(th) + y2;

	
		printKoch(step+1,x1,y1,x2,y2);
		printKoch(step+1,x2,y2,x3,y3);
		printKoch(step+1,x3,y3,x4,y4);
		printKoch(step+1,x4,y4,x5,y5);
}
int main() {
	cin >> n;
	printf("0.00000000 0.00000000\n");
	printKoch(0,0,0,100,0);
	return 0;
}
