#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <stdlib.h>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	int d = a / b;
	int r = a % b;
	cout << d << " " << r << " ";
	cout << fixed;
	cout << setprecision(20) << (double)a / (double)b << endl;
}
