#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483648
#define INT_MAX 2147483647

template <class T> T
gcd(T x, T y) { return y ? gcd(y, x % y) : x; }


int gcd3(int a, int b, int c) {
	return gcd(gcd(a, b), c);
}

int main() {
	int N;
	cin >> N;

	int sum = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			for (int k = 1; k <= N; ++k) {
				sum += gcd3(i, j, k);
			}
		}
	}
	
	cout << sum << endl;
	return 0;
}