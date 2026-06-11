#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>


using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int a, b;
	cin >> a >> b;
	cout << a / b << " " << a%b << " " << setprecision(5) << fixed << (double)a / (double)b << endl;
	return 0;
}