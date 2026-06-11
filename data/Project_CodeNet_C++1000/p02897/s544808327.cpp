#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	int N;
	double odd;
	cin >> N;
	if (N % 2 == 0) odd = N / 2;
	else odd = N / 2 + 1;
	double p = odd / N;
	cout << fixed << setprecision(6) << p << endl;
	return 0;
}