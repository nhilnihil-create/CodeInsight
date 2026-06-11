#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include <string.h>
using namespace std;

int main() {
	long long	A;
	double	B;

	cin >> A >> B;

	long long	tmp = (B + 0.001) * 100;
	long long	tmp2 = A * tmp / 100;

	cout << tmp2 << endl;

	return 0;
}