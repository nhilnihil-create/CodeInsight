#include<bits/stdc++.h>
using namespace std;

#define PI 3.14159265359

long long A, B, H, M;

int main(){
	cin >> A >> B >> H >> M;
	double x1,x2,y1,y2;
	x1 = A* cos(2.0 * PI * H/12.0 + 2.0 * PI/12 * M/60.0);
	y1 = A* sin(2.0 * PI * H/12.0 + 2.0 * PI/12 * M/60.0);
	x2 = B* cos(2.0 * PI * M/60.0);
	y2 = B* sin(2.0 * PI * M/60.0);
	printf("%.20f\n", sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)));
}