#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <numeric>
#include <math.h>

using namespace std;
double condition = 0.0;
void func()
{
	int L;
	cin >> L;
	cout << fixed << setprecision(15) << (double)(L*L*L)/27 << endl;
}

int main() {
//	while(1)
	func();
	return 0;
}
