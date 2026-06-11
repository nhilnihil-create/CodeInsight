#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <numeric>
#include <math.h>

using namespace std;

int gcd(int x, int y) { return (x % y) ? gcd(y, x % y) : y; }

void func()
{
	int K;
	int64_t ans = 0;
	cin >> K;
	for (int a = 1; a <= K; a++) {
		for (int b = 1; b <= K; b++) {
			int tmp = gcd(a, b);
			for (int c = 1; c <= K; c++) {
				ans += gcd(tmp, c);
			}
		}
	}
	cout << ans << endl;
}

int main() {

//	while (1)
		func();
	return 0;
}
