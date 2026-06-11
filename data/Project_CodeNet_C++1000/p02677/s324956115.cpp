#include <iostream>
#include <math.h>
#define PI 3.1415926535

using namespace std;

int main(){
	int a, b;
	cin >> a >> b;
	int h, m;
	cin >> h >> m;
	
	double a_rad = (((360.0 / 12.0) * (double)h)+((360.0 / (12.0*60.0))*(double)m)) / 180 * PI;
	double b_rad = (360.0 / 60.0 * (double)m) / 180.0 * PI;
	
	double a_x = (double)a * cos(a_rad);
	double a_y = (double)a * sin(a_rad);
	
	double b_x = (double)b * cos(b_rad);
	double b_y = (double)b * sin(b_rad);

	
	double ans = sqrt((a_x-b_x)*(a_x-b_x) + (a_y-b_y)*(a_y-b_y));
	
	printf("%.10f\n", ans);
	
}