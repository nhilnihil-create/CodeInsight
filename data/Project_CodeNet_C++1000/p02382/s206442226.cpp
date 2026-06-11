#include <cstdio>
#include <iostream>
#include <cmath>
#include <ctype.h>
#include <string> 
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <iomanip>
  
using namespace std;

#define pi 3.141592653589793

int main()
{
	int n;
	double x[100], y[100];
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x[i];
	}
	for(int i = 0; i < n; i++){
		cin >> y[i];
	}
	double d1 = 0, d2 = 0, d3 = 0, d4 = 0;
	for(int i = 0; i < n; i++){
		d1 += abs(x[i] - y[i]);
		d2 += (x[i] - y[i]) * (x[i] - y[i]);
		d3 += abs((x[i] - y[i]) * (x[i] - y[i]) * (x[i] - y[i]));
		d4 = max(d4, abs(x[i] - y[i]));
	}
	d2 = sqrt(d2);
	d3 = pow(d3, 1.0 / 3.0);
	printf("%f\n%f\n%f\n%f\n", d1, d2, d3, d4);
	return 0;
}