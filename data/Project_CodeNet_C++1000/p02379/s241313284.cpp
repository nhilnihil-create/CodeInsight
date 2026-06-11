#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int main() {
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double dx, dy;
    dx = x2 - x1;
    dy = y2 - y1;
    double buf;
    buf = dx * dx + dy * dy;
    double result;
    result = sqrt(buf);
    //double dout;
    //dout = result * pow(10.0, 4);
    //dout = (double)(int)(dout);
    
    //printf("%.8f", dout * pow(10.0, -4));
    
    printf("%.8f", result);
	return 0;
}

