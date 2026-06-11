#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef long long int llint;

void get_vals(llint& a, llint& b) {
	do {
		cin >> a;
	} while (a < 0 || a>100);
	do {
		cin >> b;
	} while (b < 0 || b>100);

	if (a + b < 2) {
		get_vals(a, b);
	}

}


int main() {
	llint n, m;
	get_vals(n, m);
	llint balls{ n + m };

	if (n <= 1) {
		llint top, down;
		top = m * (m - 1);
		down = 2;
		cout << top / down;
		return 0;
	}
	if (m <= 1){
		llint top, down;
		top = n * (n - 1);
		down = 2;
		cout << top / down;
		return 0;
	}

	llint top[2]{n*(n-1), m*(m-1)};
	llint down{2};
	cout << (top[0] / 2) + (top[1] / 2);

	return 0;
}