#include <iostream>
#include <vector>
#include <cstring>
#include <cctype>
#include <string>
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

int main(){
	vector<double>a(2), b(2);
	cin >> a[0] >> a[1] >> b[0] >> b[1];
	cout <<fixed<< sqrt(pow((a[0]-b[0]),double(2))+pow((a[1]-b[1]),double(2)));
	return 0;
}