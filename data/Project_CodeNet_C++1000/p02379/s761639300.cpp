#include<iostream>
#include<math.h>
using namespace std;
int main() {
	double x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	double dis = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
	printf("%.6f", dis);
	char c;
	cin >> c;
}