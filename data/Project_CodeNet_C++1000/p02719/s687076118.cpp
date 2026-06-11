#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	long long n, k;
	cin >> n >> k;
	long long half_k = k / 2;
	long long remainder = n % k;
	if (remainder > half_k) remainder = k - remainder;
	cout << remainder << endl;
	return 0;
}