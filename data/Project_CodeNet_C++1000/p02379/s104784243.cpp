#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

int main(){
	double x1, x2, w, y1, y2, h, ans;
	cin >> x1 >> y1 >> x2 >> y2;
	w = x1 - x2;
	h = y1 - y2;
	ans = w*w + h*h;
	ans = sqrt(ans);
	printf("%.8f\n", ans);
	return 0;
}