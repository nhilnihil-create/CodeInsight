#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <numeric>
#include <math.h>

using namespace std;
void func()
{
	int N, X, T;
	cin >> N >> X >> T;
	cout << (int)ceil((double)N / X) * T << endl;
}

int main() {
//	while(1)
	func();
	return 0;
}
