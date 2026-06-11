#include "iostream"
#include "math.h"
#include "algorithm"
#include "string"
#include "vector"
#include "deque"
#include "cmath"
using namespace std;
typedef long long ll;

int main() {
	int n, d;
	cin >> n >> d;
	d = 2 * d + 1;
	if (n%d == 0) {
		cout << n / d;
	}
	else {
		cout << n / d + 1;
	}
	cout << endl;
}