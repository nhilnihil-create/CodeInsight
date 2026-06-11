#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
 
int main() {
	string str;
	double x1,y1,x2,y2;
	cin >> x1>>y1>>x2>>y2;
	double ans = sqrt(pow(x1-x2,2) + pow(y1-y2,2));
	printf("%lf\n", ans);
	return 0;
}
