#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <math.h>
using namespace std;
#define _USE_MATH_DEFINES

int main() {
	double a;
	cin >> a;
	double PI = 3.141592653589793238463;
	cout << setiosflags(ios::fixed) << setprecision(10) << a*a*PI << " " << a * 2 * PI << endl;
}