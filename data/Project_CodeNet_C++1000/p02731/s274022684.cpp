#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	double a;
	cin >> a;
	cout << setprecision(8) << pow(a/3+0.0000000001, 3);
}

